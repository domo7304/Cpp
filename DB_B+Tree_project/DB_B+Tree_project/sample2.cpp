struct bp_node;
struct bp_entry {
    bool valid;  // �ش� entry�� ��ȿ�Ѱ�?
    int key; // �ش� Entry�� key��
    struct bp_node* thisnode;  // �� ��Ʈ���� �����ϴ� ���
    struct bp_node* nptr;  // �� ��Ʈ���� ����Ű�� ���
    void* dptr;  // �� ��Ʈ���� ��������� �� ����Ű�� ������
};

struct bp_node {
    bool leaf;  // Leaf node?
    int nodecnt; // ��Ʈ�� ��ü ����
    struct bp_entry entries[FANOUT]; // entry ����ü�� �迭
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
1. ������� Ž��
2. �ش� ������尡 �� á�°�?
2.1. Yes
2.1.1. Split ���� ���� -> ���ƿ��� ���� Target Leaf Node
2.2. No
2.3. Nope.
3. Key�� �ش� Leaf Node�� �ִ´�.
*/
bool insert(int key) {
    struct bp_node* node;
    bool ret = bp_find_leaf_node(key, &node);
    assert(ret != false); // ��尡 ��ǵȴٸ�... ������ �߻��մϴ�.
// �׷��� ������ �׻� ��� ����� ��Ʈ���� ������忡 ������ �Ǿ� �ֽ��ϴ�.
    if (bp_check_duplicate(node, key)) {
        printf("Key is already exist on tree.\n");
        return false;
    }
    if (BP_IS_NODE_FULL(node)) { // ��尡 �� á�ٸ�,
        node = split(node, key);      // Split������ �����մϴ�.
    }

    return bp_insert_key(node, key); // ������ insert������ �����ϸ�...
}


/* split ����
1. �ɰ��� ������ floor ((Fanout + 1) / 2)�� �ش���. (���� split_factor)
2. �ɰ��� ���ذ��� entries[split_factor + 1].key�� �ش���
3. ��, �� ����� ���� �� ��带 ������ �ɰ� ��, ��� �Է���
4. �ش� ��尡 ��Ʈ����?
4.1. Yes
4.1.1. �� ��� �Ҵ�(Non-leaf�� �Ҵ��Ѵ�.)
4.1.2. �� ���� ��Ʈ�� ������.
4.1.3. ��, �� ����� �θ� �ش� ���� �������ش�.
4.2. No
4.2.1. �ش� ��嵵 ��á��?
4.2.1.1. Yes
4.2.1.1.1. ���� �ɰ��� ���� ����
4.2.1.2. No
5. �ƹ�ư �θ� ��忡 split key�� �ְ�, �ش� ��Ʈ���� �¿��� �����͸� ��, �� ���� �ٲ��ش�.

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
    if (node == root) { // ù��° Split�� �߻��Ѵٸ� Node�� �и� Root���� Ʋ������!��
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

    // �ڽ��� �ڽĵ��� �ڱ⸦ ����Ű�� ���ľ� �մϴ�.
    bp_fix_child_parent(lnode);
    bp_fix_child_parent(rnode);

    return (split_key < key ? lnode : rnode);
}


// http://imarch.pe.kr/?p=2039