struct bp_node;
struct bp_entry {
    bool valid;  // 해당 entry가 유효한가?
    int key; // 해당 Entry의 key값
    struct bp_node* thisnode;  // 이 엔트리를 포함하는 노드
    struct bp_node* nptr;  // 이 엔트리가 가리키는 노드
    void* dptr;  // 이 엔트리가 리프노드일 때 가리키는 데이터
};

struct bp_node {
    bool leaf;  // Leaf node?
    int nodecnt; // 엔트리 전체 갯수
    struct bp_entry entries[FANOUT]; // entry 구조체의 배열
};



/* If found, then fill node variable into those leaf and
return true otherwise, fill to those parent node and return false */
bool
find_leaf_node_by_key(int key, struct bp_node** node) {
    return _find_leaf_node_by_key(root, key, node);
}

bool
_find_leaf_node_by_key(struct bp_node* node,
    int key, struct bp_node** ret) {
    if (node->leaf == true) {
        *ret = node;
        return true;
    }

    int pos = find_entry_by_key(node, key);
    struct bp_entry* entry = node->entries[pos];
    return _find_leaf_node_by_key(entry->nptr, key, ret);
}

/*
1. 리프노드 탐색
2. 해당 리프노드가 꽉 찼는가?
2.1. Yes
2.1.1. Split 연산 수행 -> 돌아오는 곳은 Target Leaf Node
2.2. No
2.3. Nope.
3. Key를 해당 Leaf Node에 넣는다.
*/
bool insert(int key) {
    struct bp_node* node;
    bool ret = bp_find_leaf_node(key, &node);
    assert(ret != false); // 노드가 상실된다면... 에러가 발생합니다.
// 그렇지 않으면 항상 모든 노드의 엔트리는 리프노드에 연결이 되어 있습니다.
    if (bp_check_duplicate(node, key)) {
        printf("Key is already exist on tree.\n");
        return false;
    }
    if (BP_IS_NODE_FULL(node)) { // 노드가 꽉 찼다면,
        node = split(node, key);      // Split연산을 수행합니다.
    }

    return bp_insert_key(node, key); // 마지막 insert연산을 수행하며...
}


/* split 연산
1. 쪼개는 갯수는 floor ((Fanout + 1) / 2)에 해당함. (변수 split_factor)
2. 쪼개는 기준값은 entries[split_factor + 1].key에 해당함
3. 좌, 우 노드의 생성 및 노드를 반으로 쪼개 좌, 우로 입력함
4. 해당 노드가 루트였나?
4.1. Yes
4.1.1. 새 노드 할당(Non-leaf로 할당한다.)
4.1.2. 새 노드로 루트로 변경함.
4.1.3. 좌, 우 노드의 부모를 해당 노드로 변경해준다.
4.2. No
4.2.1. 해당 노드도 꽉찼나?
4.2.1.1. Yes
4.2.1.1.1. 역시 쪼개기 연산 수행
4.2.1.2. No
5. 아무튼 부모 노드에 split key를 넣고, 해당 엔트리의 좌우노드 포인터를 좌, 우 노드로 바꿔준다.

*/
struct bp_node* split(struct bp_node* node, int key) {
    int split_factor = (FANOUT + 1) >> 1;
    int split_key = node->entries[split_factor + 1].key;
    struct bp_node* parent = node->parent;
    struct bp_node* lnode, * rnode;
    lnode = bp_alloc_node(node->leaf);
    rnode = bp_alloc_node(node->leaf);

    // bp_copy_node (Target Node, Node, Start from, Size)
    bp_copy_node(lnode, node, 0, split_factor + 1);
    bp_copy_node(rnode, node, 1, split_factor);
    if (node == root) { // 첫번째 Split이 발생한다면 Node는 분명 Root임이 틀림없죠!ㅋ
        node = bp_alloc_node(NON_LEAF, &super_root);
        bp_change_root(node);
        lnode->parent = node;
        rnode->parent = node;
        parent = node;
    }
    else {
        if (BP_IS_NODE_FULL(parent)) {
            parent = split(parent, split_key);
        }
        free(node);
    }
    /* bp_node_insert_key (Target, Key, Left Node, Right Node); */
    bp_node_insert_key(parent, key, lnode, rnode);

    // 자신의 자식들이 자기를 가리키게 고쳐야 합니다.
    bp_fix_child_parent(lnode);
    bp_fix_child_parent(rnode);

    return (split_key < key ? lnode : rnode);
}


// http://imarch.pe.kr/?p=2039