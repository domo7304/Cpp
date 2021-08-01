// 모든 입력 데이터는 0보다 큰 정수
// 중복은 없음
// 저장해야하는 entry의 key, value 모두 숫자라고 생각 (int)
// block의 size는 정해지 있지 않은 변수로 둘 것. 
// block size가 주어지면 그 안에 몇 개의 entry가 들어갈 수 있는지 계산하여 B를 얻어내는 식으로 구현
// 나누어 떨어지지 않는 경우 버림으로 계산
// 파일 맨 위에 12byte header를 준다. 
// header에는 BlockSize, RootBID, Depth 꼭 순서대로 기재, RootBID, Depth의 경우 계속 update

// 1. block size 만 주어 B tree 생성 - header에 저장해야함
// 2. 순서쌍 (key, value)를 쭉 입력
// 3. 생성된 B+Tree에서 key만 입력해주었을 때 (key, value) 를 출력하는 search 진행
// 4. range search 도 진행

// 모든 output은 file 생성으로
// Readme 함께 써서 제출

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class Node {
public:
    bool isLeaf;
    vector<int> keys;
    Node* ptrToNext;          //Pointer to connect next node for leaf nodes
    vector<Node*> ptrToTree;  //Array of pointers to Children sub-trees for intermediate Nodes
    vector<FILE*> dataPtr;   // Data-Pointer for the leaf node

    friend class BPTree;  // to access private members of the Node and hold the encapsulation concept
public:
    Node() {
        this->isLeaf = false;
        this->ptrToNext = NULL;
    }
};

class BPTree {
    /*
        ::For Root Node :=
            The root node has, at least two tree pointers
        ::For Internal Nodes:=
            1. ceil(maxIntChildLimit/2)     <=  #of children <= maxIntChildLimit
            2. ceil(maxIntChildLimit/2)-1  <=  #of keys     <= maxIntChildLimit -1
        ::For Leaf Nodes :=
            1. ceil(maxLeafNodeLimit/2)   <=  #of keys     <= maxLeafNodeLimit -1
    */
private:
    int maxIntChildLimit;                                   //Limiting  #of children for internal Nodes!
    int maxLeafNodeLimit;                                   // Limiting #of nodes for leaf Nodes!!!
    Node* root;                                             //Pointer to the B+ Tree root
    void insertInternal(int x, Node** cur, Node** child);  //Insert x from child in cur(parent)
    Node** findParent(Node* cur, Node* child);
    Node* firstLeftNode(Node* cur);

public:
    BPTree() {
        this->maxIntChildLimit = 4;
        this->maxLeafNodeLimit = 3;
        this->root = NULL;
    }
    BPTree(int degreeInternal, int degreeLeaf) {
        this->maxIntChildLimit = degreeInternal;
        this->maxLeafNodeLimit = degreeLeaf;
        this->root = NULL;
    }
    Node* getRoot() {
        return this->root;
    }
    int getMaxIntChildLimit() {
        return maxIntChildLimit;
    }
    int getMaxLeafNodeLimit() {
        return maxLeafNodeLimit;
    }
    void setRoot(Node* ptr) {
        this->root = ptr;
    }

    void search(int key) {
        if (root == NULL) {
            cout << "NO Tuples Inserted yet" << endl;
            return;
        }
        else {
            Node* cur = root;
            // 현재 cur가 leaf node가 아니면 
            // [ , ) 구간으로 값을 저장하므로 upper bound로 index를 얻어서 leaf node일 때까지 하위 노드로 내려가기
            while (cur->isLeaf == false) {
                int idx = upper_bound(cur->keys.begin(), cur->keys.end(), key) - cur->keys.begin();
                cur = cur->ptrToTree[idx]; 
            }

            // leaf node 까지 내려왔다면 해당 key가 존재할 시 index를 얻어올 수 있게 lower bound 로 index얻기
            int idx = lower_bound(cur->keys.begin(), cur->keys.end(), key) - cur->keys.begin();

            // while문 순회 결과 serch하고자 하는 key가 없어서 끝까지 순회했을 경우 
            // 저장되어있지 않은 key를 입력받은 것이므로 if 문을 통해 serch 종료
            if (idx == cur->keys.size() || cur->keys[idx] != key) {
                cout << "HUH!! Key NOT FOUND" << endl;
                return;
            }

            // 파일 이름에 key를 string으로 더해준 후 해당하는 이름의 file을 open
            ifstream file;
            string fileName = "DBFiles/";
            fileName += to_string(key) + ".txt";
            file.open(fileName, ios_base::in);

            char c;
            while (file.get(c)) {
                cout << c;
            }
            file.close();
            cout << endl;
        }
    }

    void insert(int key, FILE* filePtr) { //in Leaf Node
        /*
        1. node에 빈 공간이 있다면 key value 를 삽입
        2. If the node is already full, split it into two nodes, distributing the keys
        evenly between the two nodes. If the node is a leaf, take a copy of the minimum
        value in the second of these two nodes and repeat this insertion algorithm to
        insert it into the parent node. If the node is a non-leaf, exclude the middle
        value during the split and repeat this insertion algorithm to insert this excluded
        value into the parent node.
    */

        // 비어있는 트리라면 새로운 트리를 생성
        if (root == NULL) {
            root = new Node;
            root->isLeaf = true;
            root->keys.push_back(key);
            root->dataPtr.push_back(filePtr);

            return;
        }
        else {
            Node* cur = root;
            Node* parent = NULL;
            //searching for the possible position for the given key by doing the same procedure we did in search

            // 삽입할 key의 위치를 찾기 위해 leaf node까지 while문 순회
            while (cur->isLeaf == false) {
                parent = cur;
                int idx = upper_bound(cur->keys.begin(), cur->keys.end(), key) - cur->keys.begin();
                cur = cur->ptrToTree[idx];
            }

            // node에 빈 공간이 있을 경우 while문을 통해 얻어온 cur를 이용하여 key, value 삽입
            if (cur->keys.size() < maxLeafNodeLimit) {
                
                int pos = upper_bound(cur->keys.begin(), cur->keys.end(), key) - cur->keys.begin();
                cur->keys.push_back(key);
                cur->dataPtr.push_back(filePtr);

                // 삽입해야할 entry가 node 끝에 위치하는 것이 아니라면 
                // 해당 enrty pos 뒤에 있는 entry들을 한 칸씩 뒤로 shift 후 삽입
                if (pos != cur->keys.size() - 1) {
                    for (int i = cur->keys.size() - 1; i > pos; i--) {  // shifting the position for keys and datapointer
                        cur->keys[i] = cur->keys[i - 1];
                        cur->dataPtr[i] = cur->dataPtr[i - 1];
                    }
                    cur->keys[pos] = key;
                    cur->dataPtr[pos] = filePtr;
            }
            // node가 꽉 차서 split이 필요한 경우
            else {
                vector<int> virtualNode(cur->keys);
                vector<FILE*> virtualDataNode(cur->dataPtr);

                //finding the probable place to insert the key
                int i = upper_bound(cur->keys.begin(), cur->keys.end(), key) - cur->keys.begin();

                virtualNode.push_back(key);          // to create space
                virtualDataNode.push_back(filePtr);  // to create space

                if (i != virtualNode.size() - 1) {
                    for (int j = virtualNode.size() - 1; j > i; j--) {  // shifting the position for keys and datapointer
                        virtualNode[j] = virtualNode[j - 1];
                        virtualDataNode[j] = virtualDataNode[j - 1];
                    }

                    //inserting
                    virtualNode[i] = key;
                    virtualDataNode[i] = filePtr;
                }
                /*
                    BAZINGA! I have the power to create new Leaf :)
                */

                Node* newLeaf = new Node;
                newLeaf->isLeaf = true;
                new (&newLeaf->dataPtr) vector<FILE*>;
                //// now, newLeaf->ptrToTree is the active member of the union

                //swapping the next ptr
                Node* temp = cur->ptrToNext;
                cur->ptrToNext = newLeaf;
                newLeaf->ptrToNext = temp;

                //resizing and copying the keys & dataPtr to OldNode
                cur->keys.resize((maxLeafNodeLimit) / 2 + 1);//check +1 or not while partitioning
                cur->dataPtr.reserve((maxLeafNodeLimit) / 2 + 1);
                for (int i = 0; i <= (maxLeafNodeLimit) / 2; i++) {
                    cur->keys[i] = virtualNode[i];
                    cur->dataPtr[i] = virtualDataNode[i];
                }

                //Pushing new keys & dataPtr to NewNode
                for (int i = (maxLeafNodeLimit) / 2 + 1; i < virtualNode.size(); i++) {
                    newLeaf->keys.push_back(virtualNode[i]);
                    newLeaf->dataPtr.push_back(virtualDataNode[i]);
                }

                if (cur == root) {
                    /*
                        If cur is root node we create new node
                    */

                    Node* newRoot = new Node;
                    newRoot->keys.push_back(newLeaf->keys[0]);
                    new (&newRoot->ptrToTree) vector<Node*>;
                    newRoot->ptrToTree.push_back(cur);
                    newRoot->ptrToTree.push_back(newLeaf);
                    root = newRoot;
                    cout << "Created new Root!" << endl;
                }
                else {
                    // Insert new key in the parent
                    insertInternal(newLeaf->keys[0], &parent, &newLeaf);
                }
            }
        }
    }

    void insertInternal(int x, Node** cur, Node** child) {  //in Internal Nodes
        if ((*cur)->keys.size() < maxIntChildLimit - 1) {
            /*
                If cur is not full find the position for the new key.
            */
            int i = upper_bound((*cur)->keys.begin(), (*cur)->keys.end(), x) - (*cur)->keys.begin();
            (*cur)->keys.push_back(x);
            //new (&(*cur)->ptrToTree) vector<Node*>;
            //// now, root->ptrToTree is the active member of the union
            (*cur)->ptrToTree.push_back(*child);

            if (i != (*cur)->keys.size() - 1) {  // if there are more than one element
                // Different loops because size is different for both (i.e. diff of one)

                for (int j = (*cur)->keys.size() - 1; j > i; j--) {  // shifting the position for keys and datapointer
                    (*cur)->keys[j] = (*cur)->keys[j - 1];
                }

                for (int j = (*cur)->ptrToTree.size() - 1; j > (i + 1); j--) {
                    (*cur)->ptrToTree[j] = (*cur)->ptrToTree[j - 1];
                }

                (*cur)->keys[i] = x;
                (*cur)->ptrToTree[i + 1] = *child;
            }
            cout << "Inserted key in the internal node :)" << endl;
        }
        else {  //splitting
            cout << "Inserted Node in internal node successful" << endl;
            cout << "Overflow in internal:( HAIYAA! splitting internal nodes" << endl;

            vector<int> virtualKeyNode((*cur)->keys);
            vector<Node*> virtualTreePtrNode((*cur)->ptrToTree);

            int i = upper_bound((*cur)->keys.begin(), (*cur)->keys.end(), x) - (*cur)->keys.begin();  //finding the position for x
            virtualKeyNode.push_back(x);                                                                   // to create space
            virtualTreePtrNode.push_back(*child);                                                           // to create space

            if (i != virtualKeyNode.size() - 1) {
                for (int j = virtualKeyNode.size() - 1; j > i; j--) {  // shifting the position for keys and datapointer
                    virtualKeyNode[j] = virtualKeyNode[j - 1];
                }

                for (int j = virtualTreePtrNode.size() - 1; j > (i + 1); j--) {
                    virtualTreePtrNode[j] = virtualTreePtrNode[j - 1];
                }

                virtualKeyNode[i] = x;
                virtualTreePtrNode[i + 1] = *child;
            }

            int partitionKey;                                            //exclude middle element while splitting
            partitionKey = virtualKeyNode[(virtualKeyNode.size() / 2)];  //right biased
            int partitionIdx = (virtualKeyNode.size() / 2);

            //resizing and copying the keys & TreePtr to OldNode
            (*cur)->keys.resize(partitionIdx);
            (*cur)->ptrToTree.resize(partitionIdx + 1);
            (*cur)->ptrToTree.reserve(partitionIdx + 1);
            for (int i = 0; i < partitionIdx; i++) {
                (*cur)->keys[i] = virtualKeyNode[i];
            }

            for (int i = 0; i < partitionIdx + 1; i++) {
                (*cur)->ptrToTree[i] = virtualTreePtrNode[i];
            }

            Node* newInternalNode = new Node;
            new (&newInternalNode->ptrToTree) vector<Node*>;
            //Pushing new keys & TreePtr to NewNode

            for (int i = partitionIdx + 1; i < virtualKeyNode.size(); i++) {
                newInternalNode->keys.push_back(virtualKeyNode[i]);
            }

            for (int i = partitionIdx + 1; i < virtualTreePtrNode.size(); i++) {  // because only key is excluded not the pointer
                newInternalNode->ptrToTree.push_back(virtualTreePtrNode[i]);
            }

            if ((*cur) == root) {
                /*
                    If cur is a root we create a new Node
                */
                Node* newRoot = new Node;
                newRoot->keys.push_back(partitionKey);
                new (&newRoot->ptrToTree) vector<Node*>;
                newRoot->ptrToTree.push_back(*cur);
                //// now, newRoot->ptrToTree is the active member of the union
                newRoot->ptrToTree.push_back(newInternalNode);

                root = newRoot;
                cout << "Created new ROOT!" << endl;
            }
            else {
                /*
                    ::Recursion::
                */
                insertInternal(partitionKey, findParent(root, *cur), &newInternalNode);
            }
        }
    }
};