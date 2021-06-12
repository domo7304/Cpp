#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#define M 5
#define max_children M
#define max_keys max_children-1
#define min_keys (int)(ceil(M/2.0))-1 // �ּ� Ű���� ���ϴ� ��

struct BTreeNode {
    bool leaf; // leaf���� 
    int key[max_keys + 1]; // key�� ���� �迭
    int cnt_key; // Ű ���� Ȯ�ο�
    struct BTreeNode* child[max_children + 1]; // �ڽ� �����͹迭 (������ �迭��)
    int cnt_child; // �ڽ� ���� Ȯ�ο�
};

int deleteValFromNode(int val, struct BTreeNode* node);

struct BTreeNode* root; // root ��� �⺻ ����(�����ͷ�)

#include "b_tree.h"


// �˻��ϴ� �Լ�
int searchNode(struct BTreeNode* node, int val) {
    if (!node) {
        printf("Empty tree.\n");
        return 0;
    }
    struct BTreeNode* level = node;
    while (true) {
        int pos;
        for (pos = 0; pos < level->cnt_key; pos++) {
            if (val == level->key[pos]) {
                printf("key %d exists!", val);
                return 1;
            }
            else if (val < level->key[pos]) {
                break;
            }
        }
        if (level->leaf) break;
        level = level->child[pos];
    }
    printf("key %d does not exist", val);
    return 0;
}


// �����ͷ� ��带 �������, �װ� createNode��� ����ߴ�. �޾ƿ��� ���� '�ִ� ������'.
struct BTreeNode* createNode(int val) {
    struct BTreeNode* newNode; // ���ο� node ����ü ����
    newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode)); // node�� �����Ҵ�
    newNode->leaf = false; // ó���� �������δ� �ʱⰪ false��
    newNode->key[0] = val; // �� node�� 1��° key ���� �޾ƿ� ������ �ֱ�
    newNode->cnt_key = 1;
    newNode->cnt_child = 0;
    return newNode;
}

// ����� ���� �и��ؼ� �ٸ� ��忡 �й��ϴ� �Լ�
struct BTreeNode* splitNode(int pos, struct BTreeNode* node, struct BTreeNode* parent) { // ���� ���, �θ� ���, �����忡�� ���� ���� ��ġ�� �˰��ִ� pos�� ���ڷ� �ޱ�
    int median; // �и��� ���� �߾Ӱ� �˾ƾ� ��.
    median = node->cnt_key / 2; // �߾Ӱ��� ¦���̵� Ȧ���̵� 'Ű����/2' 
    struct BTreeNode* right_node; // �и� �� ���� ���� �־��� ������ ��� ����.(���� �ڽ��� ��)

    right_node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    right_node->leaf = node->leaf; // �и��� �ѰŴϱ� ���� �и��Ϸ��� ���� ���� ���ΰ� ����. �°� ���� ���� �ƴϿ����� �굵 ���� �ƴ�.
    right_node->cnt_key = 0;
    right_node->cnt_child = 0;

    int num_iter = node->cnt_key;
    for (int i = median + 1; i < num_iter; i++) { // �и��� ��忡 Ű ���(�����̵� �ƴϵ�)
        right_node->key[i - (median + 1)] = node->key[i];
        right_node->cnt_key++;
        node->cnt_key--;
    }

    if (!node->leaf) { // ���� ��尡 ������ �ƴϸ�, �ڽ� ���
        num_iter = node->cnt_child;
        for (int i = median + 1; i < num_iter; i++) { // ������ ��忡 ���� ��� �ڽ� ���� ���
            right_node->child[i - (median + 1)] = node->child[i];
            right_node->cnt_child++; // ���� ä���� ����� �ڽ� ������ ����, ���� ��忡���� ����
            node->cnt_child--;
        }
    }

    // �и��� �� ���� �ø� �θ� ��� ó��
    if (node == root) { // ��Ʈ�� �� �θ� ��� ������ ��.
        struct BTreeNode* new_parent_node;
        new_parent_node = createNode(node->key[median]); // �߾Ӱ� ������ �� �θ� ��� �����
        node->cnt_key--;
        new_parent_node->child[0] = node; // ���θ����� ���� �ڽ��� ���� ���
        new_parent_node->child[1] = right_node;

        new_parent_node->cnt_child = 2;
        return new_parent_node;
    }
    else { // ��Ʈ�� �ƴϸ�, ���� �ִ� �θ��� Ȱ��
        for (int i = parent->cnt_key; i > pos; i--) { // �θ� ��忡 �־�ߵǴϱ� �ű��ִ� Ű ��ġ �ٽ��ϱ�
            parent->key[i] = parent->key[i - 1];
            parent->child[i + 1] = parent->child[i];
        }

        parent->key[pos] = node->key[median]; // �θ� ��忡 �־�ߵ� �ڸ��� �� �ֱ�
        parent->cnt_key++; // �θ��忡 ���� �־����ϱ� Ű���� �߰�, ���� ���� Ű ���� ���̱�
        node->cnt_key--;
        parent->child[pos + 1] = right_node; // ���� ���� ���� ����Ǿ������� �����ʸ� �θ��忡 ����.
        parent->cnt_child += 1;
    }
    return node; //���� ��� ����
}


// ��忡 ���� �����ϴ� �Լ� ����ü ����(split�� ���ؼ� �θ���(parent), ���� ���(node)�� ���� ����־�� ��.) �׸��� �θ��忡�� Ư�� Ű�� ��ġ�� ���� �־�� ��.**
struct BTreeNode* insertNode(int parent_pos, int val, struct BTreeNode* node, struct BTreeNode* parent) { // ������ ��,  
    int pos; // ���� ��忡�� Ű�� ��ġ�� ���� �־�� ��. �ֳĸ� �������� �ϴ� ���� ��ġ�� ã�ƾ� �ϱ� ����.
    for (pos = 0; pos < node->cnt_key; pos++) {// pos ��ġ�� 0���� �ؼ�, ���� ����� Ű ������ŭ Ž��
        if (val == node->key[pos]) { // node�� pos��° Ű�� val�� ������
            printf("Duplicates are not permitted!\n");
            return node;
        }
        else if (val < node->key[pos]) { // val�� node�� pos��° Ű���� ������ �� pos���� �����.
            break;
        }
    }// ���� val�� �� node�� �ִ� ������ ũ�� �翬�� ������ pos�� ���� ����.
    if (!node->leaf) { // node leaf ���ΰ� false�̸�, leaf�� �ƴϸ�
        node->child[pos] = insertNode(pos, val, node->child[pos], node); // node�� pos��° �ڽ� ��忡 insertNode ���� ��´�. ��ͷ� �ڽ��� Ž���ϱ� ���� �� ��.
        if (node->cnt_key == max_keys + 1) { // ���� ��� Ű ������ ��Ģ���� ����Ű�����
            node = splitNode(parent_pos, node, parent); // �� �������� �и��� �ؾ� ��.
        }
    }
    else { // leaf�� ���� ���� ����
        for (int i = node->cnt_key; i > pos; i--) { // ���������� val�� �����ؾ� �ϴ� ��ġ�� �ִ� �������� ������ �ڷ� ����� �۾��� �Ѵ�.
            node->key[i] = node->key[i - 1]; // Ű�� �ڷ� �� ĭ�� ���� �۾�.
            node->child[i + 1] = node->child[i]; // �ڽĵ� ��������.
        }

        node->key[pos] = val; // val�� �����ؾ� �ϴ� ��ġ�� val ����.
        node->cnt_key++; // �ϳ� ���������� Ű ���� ����
        if (node->cnt_key == max_keys + 1) { // leaf ��尡 �� á���� �и��� ���ش�.
            node = splitNode(parent_pos, node, parent);
        }
    }
    return node; // node�� ���� �־��ִϱ� �� node�� ��ȯ�ؾ� ��. �׷��� ��� ����Ǿ ���� ��� ����.

}

// ���� �Լ� ���� (���� : �޾ƾ� �ϴ� ��)
void insert(int val) {
    if (!root) { // root�� ������
        root = createNode(val); // root�� ������.
        root->leaf = true; // ó�� ��������°Ŵϱ� root���� leaf ���.
        return;
    }
    else { // ��Ʈ�� ������
        root = insertNode(0, val, root, root); // ó������ root�� �θ����� �������.
    }
}

// ������ �� ��ġ�� �Լ�
void mergeNode(struct BTreeNode* par_node, int node_pos, int mer_node_pos) {
    // ���� ��带 ������ ������ ���� merge�Ǵ� ��ü�� ���� ��尡 �ǰ� ������ ����.(���� ����) / node_pos�� ������ Ű�� �����ִ� ��尡 �� ���� �ְ� �ȵɼ��� ����.
    int merge_idx = par_node->child[mer_node_pos]->cnt_key; // merge�� ��ü ����ʿ� merge�� Ű ��ġ�� �����Ѵ�.
    par_node->child[mer_node_pos]->key[merge_idx] = par_node->key[mer_node_pos]; //�θ����� Ű�� merge��.
    par_node->child[mer_node_pos]->cnt_key++;

    for (int i = 0; i < par_node->child[node_pos]->cnt_key; i++) { // ����� ��忡�� �� Ű�� ������ �ּ� Ű ���� ������ �ȵ� �� ����. ���� Ű ���� merge�� ���� �Űܾ� ��. ����Ű�� ������ �ƿ� for���� �ȵ��ư�.
        par_node->child[mer_node_pos]->key[merge_idx + 1 + i] = par_node->child[node_pos]->key[i]; // Ű ������ 2�� -> i�� 0, merge idx ������ Ű/ Ű ������ �þ�� i�� �ϳ��� �� �þ. 
        par_node->child[mer_node_pos]->cnt_key++;
    }

    int merge_childidx = par_node->child[mer_node_pos]->cnt_child; //merge�� ��� ���κ����� �Űܾ� �ϴ� ���κ� idx ����.
    for (int i = 0; i < par_node->child[node_pos]->cnt_child; i++) { // ����� ��忡�� Ű�� ����� ���� �ڽ��� ������. �³׸� merge�� ���� �Űܾ� �Ѵ�.
        par_node->child[mer_node_pos]->child[merge_childidx + i] = par_node->child[node_pos]->child[i];
        par_node->child[mer_node_pos]->cnt_child++;
    }

    free(par_node->child[node_pos]); // merge �ǰ� ���� �ݴ��� ���� �ʿ������ �޸𸮿��� ������

    for (int i = mer_node_pos; i < (par_node->cnt_key) - 1; i++) { //�θ� ����� Ű �ϳ��� �̹� �ڽ� ���� ���յǾ����� �������ؾ� ��.
        par_node->key[i] = par_node->key[i + 1];
    }
    par_node->cnt_key--;

    for (int i = mer_node_pos + 1; i < (par_node->cnt_child) - 1; i++) { // �θ� ��忡�� ���� �� �� ���� �� �ڿ� �ٸ� �ڽĵ� ���� �� ������ ��迭 �ؾ� ��. merge�� ��� �� ������ ����� ��.
        par_node->child[i] = par_node->child[i + 1];
    }
    par_node->cnt_child--;
}

// ���ʿ��� ������ �Լ�
void borrowFromLeft(struct BTreeNode* par_node, int cur_node_pos) { // �θ� ���� ���� ��� pos��ġ�� ���ڷ� ����. �̹� ���� ����� Ű�� ��������. cnt_key�� �ּһ��� Ȥ�� �̸��ϰ���.
    int tenant_idx = 0; // ������ ��ü��忡 �����ִ� Ű�� ������ ��ġ.

    // ������ ���� �ڸ��� �����ؾ� �ϱ� ������ �����ִ°Ÿ� ��ĭ �� �ڷ� �̷�� ��.(�����ִ°� ��� ����). borrowFromRight�� �ٸ��� ���� �ڸ� ������ �ؾ� ��.
    for (int i = 0; i < par_node->child[cur_node_pos]->cnt_key; i++) {
        par_node->child[cur_node_pos]->key[i + 1] = par_node->child[cur_node_pos]->key[i];
    }
    par_node->child[cur_node_pos]->key[tenant_idx] = par_node->key[cur_node_pos - 1]; // ������ Ű�� �������� �� �θ𿡰Լ� �����´�. ���⼭�� ���ʿ��� �������ϱ�, cur_node_pos(������ �ڽ� ����Ű�� ��ġ)���� 1�� ���� �θ��� Ű ��ġ�� ��. �׸��� ��������� Ű�� ���� �ö󰡴� ��.
    par_node->child[cur_node_pos]->cnt_key++;

    int idx_from_sib_topar = (par_node->child[cur_node_pos - 1]->cnt_key) - 1; // �θ��� Ű�� ������ �������ϱ� ���� ��� �� ������ Ű�� �ϳ� �θ�� �÷��� ��. 
    par_node->key[cur_node_pos - 1] = par_node->child[cur_node_pos - 1]->key[idx_from_sib_topar]; // �θ���� ������ ��������� Ű�� ���´�. ���⼱ ���� �������.
    par_node->child[cur_node_pos - 1]->cnt_key--;

    // �������� Ű�� ���������� �ڽĵ� ������ �ؾ���. �ڽ� ��ġ ������ ����.(�� ĭ�� ������ �����)
    if (par_node->child[cur_node_pos - 1]->cnt_child > 0) { // ���� ��� �ڽ��� �ִ� ��쿡��
        int tenant_childidx = (par_node->child[cur_node_pos - 1]->cnt_child) - 1; // tenant ��忡�ٰ� ��������� ���� �� �ڽ� ��ġ�� ��ߵǱ� ������ �� �ε��� ����.
        // �ڽ� ��ġ ����. borrowFromRight�� �ٸ��� �ű�� �� �̸� �����ؾ� ��. 
        for (int i = par_node->child[cur_node_pos]->cnt_child; i > 0; i--) { // �ڿ������� �����ؼ� �տ��� �ڷ� �ű�� ����.
            par_node->child[cur_node_pos]->child[i] = par_node->child[cur_node_pos]->child[i - 1];
        }

        par_node->child[cur_node_pos]->child[0] = par_node->child[cur_node_pos - 1]->child[tenant_childidx]; // ���� ��� �ڽ� ������. ������ �ڽ� ���� ��ġ�� ���� ����� 1��° ��ġ.
        par_node->child[cur_node_pos]->cnt_child++;

        par_node->child[cur_node_pos - 1]->cnt_child--;
    }
}

// �����ʿ��� ������ �Լ�
void borrowFromRight(struct BTreeNode* par_node, int cur_node_pos) { // �θ� ���� ���� ��� pos��ġ�� ���ڷ� ����. �̹� ���� ����� Ű�� ��������. cnt_key�� �ּһ��� Ȥ�� �̸��ϰ���.
    int tenant_idx = par_node->child[cur_node_pos]->cnt_key; // ������ ��ü��忡 �����ִ� Ű�� ������ ��ġ.
    par_node->child[cur_node_pos]->key[tenant_idx] = par_node->key[cur_node_pos]; // ������ Ű�� �������� �� �θ𿡰Լ� �����´�. �׸��� ��������� Ű�� ���� �ö󰡴� ��.
    par_node->child[cur_node_pos]->cnt_key++;

    int idx_from_sib_topar = 0;
    par_node->key[cur_node_pos] = par_node->child[cur_node_pos + 1]->key[idx_from_sib_topar]; // �θ���� ������ ��������� Ű�� ���´�.

    // // �������� Ű�� ���������ϱ� ��ġ ������ �ؾ� �Ѵ�.(�� ĭ�� ������ �����)
    for (int i = 0; i < (par_node->child[cur_node_pos + 1]->cnt_key) - 1; i++) {
        par_node->child[cur_node_pos + 1]->key[i] = par_node->child[cur_node_pos + 1]->key[i + 1];
    }
    par_node->child[cur_node_pos + 1]->cnt_key--;

    int idx_from_sib = 0;
    // �������� Ű�� ���������� �ڽĵ� ������ �ؾ���. �ڽ� ��ġ ������ ����.(�� ĭ�� ������ �����)
    if (par_node->child[cur_node_pos + 1]->cnt_child > 0) { // �ڽ��� �ִ� ��쿡��
        int tenant_childidx = par_node->child[cur_node_pos]->cnt_child; // tenant ��忡 ������ �ڽ��� �� ��ġ
        par_node->child[cur_node_pos]->child[tenant_childidx] = par_node->child[cur_node_pos + 1]->child[idx_from_sib]; // ���� ��� �ڽ� ������.
        par_node->child[cur_node_pos]->cnt_child++;

        // �ڽ� ��ġ ���� 
        for (int i = 0; i < par_node->child[cur_node_pos + 1]->cnt_child - 1; i++) {
            par_node->child[cur_node_pos + 1]->child[i] = par_node->child[cur_node_pos + 1]->child[i + 1];
        }
        par_node->child[cur_node_pos + 1]->cnt_child--;
    }
}

void balanceNode(struct BTreeNode* node, int child_pos) { // ���� ���� �ڽĳ�忡���� ��ġ�� ���ڷ� �޴� �Լ�(������,������ ����)
    if (child_pos == 0) { // �ڽĳ�� Ű ��ġ�� �� �����϶��� ������ �θ�,������ ���� ��.
        if (node->child[child_pos + 1]->cnt_key > min_keys) { // (�ڽĳ�� ����) ������ Ű������ �ּҼ��� ���� �� �μ�����
            borrowFromRight(node, child_pos);
        }
        else { // ������ Ű������ �ּҼ��� ���� �μ�����
            mergeNode(node, child_pos + 1, child_pos); // �θ���(������)�� �ڽ� ��ġ�� �ڱ� ���� ��ġ�� ���� �Ѱ���.  
        }
        return;
    }

    else if (child_pos == (node->cnt_key)) { // �ڽĳ�� Ű ��ġ�� �� �������� ���� ���� �θ�, ���� ���� ��.
        if (node->child[child_pos - 1]->cnt_key > min_keys) { // �ڽĳ�� ����, ���� ������ Ű������ �ּҼ��� ���� �� �μ��� ��
            borrowFromLeft(node, child_pos);
        }
        else { // �ּҼ��� ���� �μ��� ��
            mergeNode(node, child_pos, child_pos - 1); // �θ���(������)�� ����� ���� ���մ�� ��� ��ġ�� ���� �Ѱ���.  
        }
        return;
    }
    else { // �� ����,�� ������ ���� �� �̿�
        if (node->child[child_pos - 1]->cnt_key > min_keys) {
            borrowFromLeft(node, child_pos);
        }
        else if (node->child[child_pos + 1]->cnt_key > min_keys) {
            borrowFromRight(node, child_pos);
        }
        else {
            mergeNode(node, child_pos, child_pos - 1); // �شܿ� �ִ� �ڽ� ���� �� �� ������ ��ġ�� ������ ������ ��
        }
        return;
    }
}

// ���γ�� �������� �ڽĵ��� merge�ؾ��ϴ� ���̽�
int mergeChildNode(struct BTreeNode* par_node, int cur_node_pos) {
    int mergeidx = par_node->child[cur_node_pos]->cnt_key; // merge�� ���� �������� �ϴµ� �ڽĳ�忡�� ������ ��ġ ����.
    // �ٷ� ������ �ʰ� ��ġ���� �ϴ� ��忡 ������� �ϴ� �θ���(���γ��)�� ���� ��ħ. �ֳ�? �� ������ �ٷ� ����� �ڽĳ�常 ��ġ��, ��ġ���� �ϴ� ��� �ؿ� �� �ڽĳ�尡 ���� ��쿡�� �ڽ� 1���� �������� ��. 
    // �׷��� �ϴ� �θ����� ���� �ְ� �ű⼭ �� ��ͷ� ���� �� �ڽ��� ��ġ���� �������� �ؼ� �ڽļ��� �ذ��ؾ� ��.
    int val_par_node = par_node->key[cur_node_pos]; // ������� �θ� ����� ���� ���
    par_node->child[cur_node_pos]->key[mergeidx] = par_node->key[cur_node_pos];
    par_node->child[cur_node_pos]->cnt_key++;

    // ��ġ���� ��忡 ���� ��� ���� ������ ��. (���� �Լ��� ����)
    for (int i = 0; i < par_node->child[cur_node_pos + 1]->cnt_key; i++) {
        par_node->child[cur_node_pos]->key[mergeidx + 1 + i] = par_node->child[cur_node_pos + 1]->key[i];
        par_node->child[cur_node_pos]->cnt_key++;
    }
    // ������� �ڽĵ� ���;� ��.
    for (int i = 0; i < par_node->child[cur_node_pos + 1]->cnt_child; i++) {
        par_node->child[cur_node_pos]->child[mergeidx + 1 + i] = par_node->child[cur_node_pos + 1]->child[i];
        par_node->child[cur_node_pos]->cnt_child++;
    }

    // �θ���(���γ��)�� Ű�� �����ϱ� ��迭 & �ڽĵ� ��迭
    for (int i = cur_node_pos; i < par_node->cnt_key; i++) {
        par_node->key[i] = par_node->key[i + 1];
        par_node->cnt_key--;
    }
    for (int i = cur_node_pos + 1; i < par_node->cnt_child; i++) {
        par_node->child[i] = par_node->child[i + 1];
        par_node->cnt_child--;
    }
    return val_par_node; // �θ��忡�� ���ȴ� ���� ����� ���� �ϴ� ����. ���� �����ϴ� �Լ����� ������ ����.

}

// predecessor ã�� �Լ�
int findPredecessor(struct BTreeNode* cur_node) {
    int predecessor;
    if (cur_node->leaf) { //���� Ž����尡 �����̸�, ã�� �� ����.
        return cur_node->key[cur_node->cnt_key - 1]; //���� ��忡�� ���� ū Ű �ָ� ��.(predecessor ����)
    }
    return findPredecessor(cur_node->child[(cur_node->cnt_child) - 1]); // Ž���� ������ ū �� �ڽ����� Ž���ؾ� ��.
}
// predecessor ã�Ƽ� ���γ�忡 ������ �Լ�
int overrideWithPredecessor(struct BTreeNode* par_node, int pos_std_search) {
    int predecessor = findPredecessor(par_node->child[pos_std_search]); // predecessor�� ��ͷ� �� �������� ã�� �Լ� ȣ��. �θ� ���� Ÿ�� ������ ��ġ�� ���ڷ� ��.
    par_node->key[pos_std_search] = predecessor; // ������� �ϴ� ���γ���� ���� ã�� predecessor�� ��ü ����.
    return predecessor;
}

// suceessor ã�� �Լ�
int findSuccessor(struct BTreeNode* cur_node) {
    int successor;
    if (cur_node->leaf) { //���� Ž����尡 �����̸�, ã�� �� ����.
        return cur_node->key[0]; //���� ��忡�� ���� ���� Ű �ָ� ��.(successor ����)
    }
    return findSuccessor(cur_node->child[0]); // Ž���� ������ ���� �� �ڽ����� Ž���ؾ� ��.
}
// successor ã�Ƽ� ���γ�忡 ������ �Լ�
int overrideWithSuccessor(struct BTreeNode* par_node, int pos_std_search) {
    int successor = findSuccessor(par_node->child[pos_std_search + 1]); // successor�� ��ͷ� �� �������� ã�� �Լ� ȣ��. �θ� ���� Ÿ�� ������ ��ġ(���������� ���ߵ�.)�� ���ڷ� ��.
    par_node->key[pos_std_search] = successor; // ������� �ϴ� ���γ���� ���� ã�� successor�� ��ü ����.
    return successor;
}

// ���� ��忡�� ���� ����� �Լ�
void deleteInnerNode(struct BTreeNode* cur_node, int cur_node_pos) {
    int cessor = 0; // predecessor Ȥ�� successor�� ���� ��� || merge�� ����� ã�� ���� ���� ����
    int deletion_for_merge = 0;
    // ���� ������ �� ����� �ڽ��� �� ������ Ȯ��, predeȤ�� successor�� ã�ƾ� �ϱ⶧��. ���� ������ ������ ���� ���� ����.
    if (cur_node->child[cur_node_pos]->cnt_key >= cur_node->child[cur_node_pos + 1]->cnt_key) {
        if (cur_node->child[cur_node_pos]->cnt_key > min_keys) { // �ڽ� Ű������ �ּҹ��� �ν��� ������ predecessor ã�� ����.
            cessor = overrideWithPredecessor(cur_node, cur_node_pos);
            deleteValFromNode(cessor, cur_node->child[cur_node_pos]); // ã�� predecessor�� ���� �÷��� ��. �ٵ� �� ������ �ᱹ �ش� ������忡�� ���� ����°� ȿ���� �����ϴ� �Լ� ȣ��.
        }
        else {
            deletion_for_merge = mergeChildNode(cur_node, cur_node_pos);
            deleteValFromNode(deletion_for_merge, cur_node->child[cur_node_pos]);
        }
    }
    else {
        if (cur_node->child[cur_node_pos + 1]->cnt_key > min_keys) {
            cessor = overrideWithSuccessor(cur_node, cur_node_pos);
            deleteValFromNode(cessor, cur_node->child[cur_node_pos + 1]); // successor ã���� �̰͵� ������忡�� ����� ȿ���� ���� ��.
        }
        else {
            deletion_for_merge = mergeChildNode(cur_node, cur_node_pos);
            deleteValFromNode(deletion_for_merge, cur_node->child[cur_node_pos]);
        }

    }

}

// ���� ����� ���� �־��ָ� ����� �Լ�.
int deleteValFromNode(int val, struct BTreeNode* node) {
    int pos; // ������� ����� ������ ��ġ�� ����.    
    int flag = false; // ���������� ���θ� �˱� ���� flag�� ����
    for (pos = 0; pos < node->cnt_key; pos++) { // val�� ���������ϴ� �� ��ġ�� ã�ƾ� ��.���� ����� Ű ������ŭ Ž��
        if (val == node->key[pos]) { // ���� ����� Ű �迭���� pos�� val�� ������
            flag = true; // ã�Ҵٴ� ǥ��
            break;
        }
        else if (val < node->key[pos]) { // Ű �迭�� pos ��ġ ���� val���� ũ�� �� ��ġ���� �����. �ű⿡�� �Ʒ��� �� ���� �Ѵ�.
            break;
        }
    } // �̰� �����ٴ°� �� ��忡�� (�߰� Ž����) pos��ġ�� �������ٴ� �� 
    if (flag) { // flag�� true�̸� ������ �����ϴ� �۾� �ǽ�
        if (node->leaf) {  // �������� �����ؾ� �ϸ�
            for (int i = pos; i < node->cnt_key; i++) { // ����� pos��ġ���� Ű ������ŭ Ž��
                node->key[i] = node->key[i + 1]; // ������� Ű ��ġ�� �� ���� Ű�� �����
            }
            node->cnt_key--;
        }
        else { // ���ο��� �����ؾ� �ϸ�
            deleteInnerNode(node, pos); //���� ����� ���� �����ϴ� �Լ� ����. ���� ���� �����忡���� �� ��ġ�� ���ڷ� �ѱ�.
        }
        return flag;
    }
    else { // flag�� false�̸�(������� ���� ��ã�� ��)
        if (node->leaf) { //leaf ����̸�
            return flag;
        }
        else { // ������� ���� �� ã�Ҵµ� ���� ����̸� �� ������.
            flag = deleteValFromNode(val, node->child[pos]); //val�̶� �������� pos��° �ڽ� �Ѱܼ� flag �ޱ�
        }
    }
    if (node->child[pos]->cnt_key < min_keys) { // (��Ͱ� ������ �ٽ� �ö�µ�)����ó���ߴ� �ڽ� ����� Ű ������ �ּҼ��� ���� �μ����� ��
        balanceNode(node, pos); // ������, �����ϴ� �ϴ� �Լ� ���� (���� ���� �ڽĳ���� pos��ġ�� ���ڷ�)
    }

    return flag;
}

// ����� �Լ�
void delete(struct BTreeNode* node, int val) { // ���� ���� ������� ���� ���ڷ� ����.
    if (!node) { // ���� ���� ��忡 �ƿ� ���� ������
        printf("Empty tree!!\n");
        return;
    }
    int flag = deleteValFromNode(val, node); // ���� ��� ������ ���� ����� �Լ� ȣ��. ����� ���̶� ���� ��带 ���ڷ� ����. ������ flag�� ����.
    if (!flag) { // flag�� 0�̸� ����.
        printf("%d does not exist in this tree. \n", val); // �Լ� ������ ��ã���� �÷��װ� 0�ΰŴϱ� ���� �޼��� ���
        return;
    }
    if (node->cnt_key == 0) {  // deleteVal�� �ϰ� ���� node�� Ű������ 0�� �� = ���� ��忡 �ƹ��͵� ��� ��ȭ�� �ʿ���.
        node = node->child[0]; // ���� ��带 ���� ���� �ڽ� ���� ����.
    }
    root = node;

}


// Ʈ�� ����Ʈ �ϴ� �Լ�
void printTree(struct BTreeNode* node, int level) {			 // BƮ�� �׸���
    if (!node) { 											 // empty tree!
        printf("Empty tree!!\n");
        return;
    }
    printf("Level %d :   ", level);
    for (int i = 0; i < level - 1; i++) {
        printf("            ");
    }
    for (int i = 0; i < node->cnt_key; i++) {
        printf("%d ", node->key[i]);
    }
    printf("\n");
    level++;
    for (int i = 0; i < node->cnt_child; i++) {
        printTree(node->child[i], level);
    }
}

/*MAIN******************************************************************************************************/
int main(void) {

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);
    insert(110);
    insert(120);
    insert(130);
    insert(140);
    insert(150);
    insert(160);
    insert(170);
    insert(180);
    insert(190);
    insert(200);
    insert(210);
    insert(220);
    insert(230);
    insert(240);
    insert(250);
    insert(260);

    insert(9);
    insert(39);
    insert(101);
    insert(102);
    insert(103);
    insert(104);
    insert(161);
    insert(191);
    insert(251);

    printTree(root, 1);
    printf("****************************************************\n");
    delete(root, 103);
    delete(root, 70);
    delete(root, 130);
    delete(root, 104);
    delete(root, 60);
    delete(root, 120);
    delete(root, 240);
    delete(root, 160);
    printTree(root, 1);

    searchNode(root, 30);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define M 3
#define max_children M
#define max_keys max_children-1
#define min_keys (int)(ceil(M/2.0))-1 // �ּ� Ű���� ���ϴ� ��

struct BTreeNode {
    bool leaf; // leaf���� 
    bool end_leaf;
    int key[max_keys + 1]; // key�� ���� �迭
    int cnt_key; // Ű ���� Ȯ�ο�
    struct BTreeNode* child[max_children + 1]; // �ڽ� �����͹迭 (������ �迭��)
    int child_data[max_keys + 1];
    struct BTreeNode* next;
    int cnt_child; // �ڽ� ���� Ȯ�ο�
};
struct BTreeNode* root; // root ��� �⺻ ����(�����ͷ�)
struct BTreeNode* createNode(int val);

/*SEARCH******************************************************************************************************/
int searchNode(struct BTreeNode* node, int val) {			// TO DO:: ����Ž��
    if (!node) { 											// empty tree!
        printf("Empty tree!!\n");
        return 0;
    }
    struct BTreeNode* level = node;							// root���� leaf���� Ž��
    while (1) {
        int pos;
        for (pos = 0; pos < level->cnt_key; pos++) {
            if (val == level->key[pos]) {					// ã���� ���� 1
                printf("%d exist!!\n", val);
                return 1;
            }
            else if (val < level->key[pos]) {
                break;
            }
        }
        if (level->leaf) break;
        level = level->child[pos];
    }
    printf("%d not exist!!\n", val);							// leaf �����ͼ��� ��ã���� ���� 0
    return 0;
}


// �����ͷ� ��带 �������, �װ� createNode��� ����ߴ�. �޾ƿ��� ���� '�ִ� ������'.
struct BTreeNode* createNode(int val) {
    struct BTreeNode* newNode; // ���ο� node ����ü ����
    newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode)); // node�� �����Ҵ�
    newNode->leaf = false; // ó���� �������δ� �ʱⰪ false��
    newNode->key[0] = val; // �� node�� 1��° key ���� �޾ƿ� ������ �ֱ�
    newNode->cnt_key = 1;
    newNode->cnt_child = 0;
    newNode->end_leaf = false;
    return newNode;
}

// ����� ���� �и��ؼ� �ٸ� ��忡 �й��ϴ� �Լ�
struct BTreeNode* splitNode(int pos, struct BTreeNode* node, struct BTreeNode* parent) { // ���� ���, �θ� ���, �����忡�� ���� ���� ��ġ�� �˰��ִ� pos�� ���ڷ� �ޱ�
    int median; // �и��� ���� �߾Ӱ� �˾ƾ� ��.
    median = node->cnt_key / 2; // �߾Ӱ��� ¦���̵� Ȧ���̵� 'Ű����/2' 
    struct BTreeNode* right_node; // �и� �� ���� ���� �־��� ������ ��� ����.(���� �ڽ��� ��)

    right_node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    right_node->leaf = node->leaf; // �и��� �ѰŴϱ� ���� �и��Ϸ��� ���� ���� ���ΰ� ����. �°� ���� ���� �ƴϿ����� �굵 ���� �ƴ�.
    right_node->cnt_key = 0;
    right_node->cnt_child = 0;
    right_node->end_leaf = node->end_leaf;
    right_node->next = node->next;


    if (node->leaf) { // ���� ��尡 �����̸�, �ڽ� ���
        node->next = right_node;
        node->end_leaf = false;
        int num_iter = node->cnt_key;
        for (int i = median; i < num_iter; i++) { // ������ ��忡 ���� ��� �ڽ� ���� ���
            right_node->key[i - median] = node->key[i];
            right_node->child_data[i - median] = node->child_data[i];
            right_node->cnt_key++; // ���� ä���� ����� �ڽ� ������ ����, ���� ��忡���� ����
            node->cnt_key--;
        }
    }
    else {
        int num_iter = node->cnt_key;
        for (int i = median + 1; i < num_iter; i++) { // ������ ��忡 ���� ��� �ڽ� ���� ���
            right_node->key[i - (median + 1)] = node->key[i];
            right_node->cnt_key++; // ���� ä���� ����� �ڽ� ������ ����, ���� ��忡���� ����
            node->cnt_key--;
        }

        num_iter = node->cnt_child;
        for (int i = median + 1; i < num_iter; i++) { // �и��� ��忡 Ű ���(�����̵� �ƴϵ�)
            right_node->child[i - (median + 1)] = node->child[i];
            right_node->cnt_child++;
            node->cnt_child--;
        }
    }

    // �и��� �� ���� �ø� �θ� ��� ó��
    if (node == root) { // ��Ʈ�� �� �θ� ��� ������ ��.
        struct BTreeNode* new_parent_node;
        new_parent_node = createNode(node->key[median]); // �߾Ӱ� ������ �� �θ� ��� �����
        if (!node->leaf) {
            node->cnt_key--;
        }
        new_parent_node->child[0] = node; // ���θ����� ���� �ڽ��� ���� ���
        new_parent_node->child[1] = right_node;
        new_parent_node->cnt_child = 2;
        return new_parent_node;
    }
    else { // ��Ʈ�� �ƴϸ�, ���� �ִ� �θ��� Ȱ��
        for (int i = parent->cnt_key; i > pos; i--) { // �θ� ��忡 �־�ߵǴϱ� �ű��ִ� Ű ��ġ �ٽ��ϱ�
            parent->key[i] = parent->key[i - 1];
            parent->child[i + 1] = parent->child[i];
        }

        parent->key[pos] = node->key[median]; // �θ� ��忡 �־�ߵ� �ڸ��� �� �ֱ�
        parent->cnt_key++; // �θ��忡 ���� �־����ϱ� Ű���� �߰�, ���� ���� Ű ���� ���̱�
        if (!node->leaf) {
            node->cnt_key--;
        }
        parent->child[pos + 1] = right_node; // ���� ���� ���� ����Ǿ������� �����ʸ� �θ��忡 ����.
        parent->cnt_child += 1;
    }
    return node; //���� ��� ����
}

struct BTreeNode* insertNode(int parent_pos, int val, struct BTreeNode* node, struct BTreeNode* parent, int value) { // ������ ��,  
    int pos; // ���� ��忡�� Ű�� ��ġ�� ���� �־�� ��. �ֳĸ� �������� �ϴ� ���� ��ġ�� ã�ƾ� �ϱ� ����.
    for (pos = 0; pos < node->cnt_key; pos++) {// pos ��ġ�� 0���� �ؼ�, ���� ����� Ű ������ŭ Ž��
        if (val == node->key[pos]) { // node�� pos��° Ű�� val�� ������
            printf("Duplicates are not permitted!\n");
            return node;
        }
        else if (val < node->key[pos]) { // val�� node�� pos��° Ű���� ������ �� pos���� �����.
            break;
        }
    }// ���� val�� �� node�� �ִ� ������ ũ�� �翬�� ������ pos�� ���� ����.
    if (!node->leaf) { // node leaf ���ΰ� false�̸�, leaf�� �ƴϸ�
        node->child[pos] = insertNode(pos, val, node->child[pos], node, value); // node�� pos��° �ڽ� ��忡 insertNode ���� ��´�. ��ͷ� �ڽ��� Ž���ϱ� ���� �� ��.
        if (node->cnt_key == max_keys + 1) { // ���� ��� Ű ������ ��Ģ���� ����Ű�����
            node = splitNode(parent_pos, node, parent); // �� �������� �и��� �ؾ� ��.
        }
    }
    else { // leaf�� ���� ���� ����
        for (int i = node->cnt_key; i > pos; i--) { // ���������� val�� �����ؾ� �ϴ� ��ġ�� �ִ� �������� ������ �ڷ� ����� �۾��� �Ѵ�.
            node->key[i] = node->key[i - 1]; // Ű�� �ڷ� �� ĭ�� ���� �۾�.
            node->child[i + 1] = node->child[i]; // �ڽĵ� ��������.
        }

        node->key[pos] = val; // val�� �����ؾ� �ϴ� ��ġ�� val ����.
        // node -> child_data = value;
        node->child_data[pos] = value;
        node->cnt_key++; // �ϳ� ���������� Ű ���� ����
        if (node->cnt_key == max_keys + 1) { // leaf ��尡 �� á���� �и��� ���ش�.
            node = splitNode(parent_pos, node, parent);
        }
    }
    return node; // node�� ���� �־��ִϱ� �� node�� ��ȯ�ؾ� ��. �׷��� ��� ����Ǿ ���� ��� ����.
}


// ���� �Լ� ���� (���� : �޾ƾ� �ϴ� ��)
void insert(int val, int value) {
    if (!root) { // root�� ������
        root = createNode(val); // root�� ������.
        root->leaf = true; // ó�� ��������°Ŵϱ� root���� leaf ���.
        root->end_leaf = true;
        return;
    }
    else { // ��Ʈ�� ������
        root = insertNode(0, val, root, root, value); // ó������ root�� �θ����� �������.
    }
}

// ������ �� ��ġ�� �Լ�
void mergeNode(struct BTreeNode* par_node, int node_pos, int mer_node_pos) {

    if (par_node->child[node_pos]->leaf) {
        int merge_idx = par_node->child[mer_node_pos]->cnt_key; // merge�� ��ü ����ʿ� merge�� Ű ��ġ�� �����Ѵ�.
        for (int i = 0; i < par_node->child[node_pos]->cnt_key; i++) { // ����� ��忡�� �� Ű�� ������ �ּ� Ű ���� ������ �ȵ� �� ����. ���� Ű ���� merge�� ���� �Űܾ� ��. ����Ű�� ������ �ƿ� for���� �ȵ��ư�.
            par_node->child[mer_node_pos]->key[merge_idx + i] = par_node->child[node_pos]->key[i]; // Ű ������ 2�� -> i�� 0, merge idx ������ Ű/ Ű ������ �þ�� i�� �ϳ��� �� �þ. 
            par_node->child[mer_node_pos]->cnt_key++;
        }
        par_node->child[mer_node_pos]->next = par_node->child[node_pos]->next; //�θ����� Ű�� merge��.
        par_node->child[mer_node_pos]->end_leaf = par_node->child[node_pos]->end_leaf;

        for (int i = mer_node_pos; i < (par_node->cnt_key) - 1; i++) { //�θ� ����� Ű �ϳ��� �̹� �ڽ� ���� ���յǾ����� �������ؾ� ��.
            par_node->key[i] = par_node->key[i + 1];
        }
        par_node->cnt_key--;

        for (int i = mer_node_pos + 1; i < (par_node->cnt_child) - 1; i++) { // �θ� ��忡�� ���� �� �� ���� �� �ڿ� �ٸ� �ڽĵ� ���� �� ������ ��迭 �ؾ� ��. merge�� ��� �� ������ ����� ��.
            par_node->child[i] = par_node->child[i + 1];
        }
        par_node->cnt_child--;
    }
    else {
        // ���� ��带 ������ ������ ���� merge�Ǵ� ��ü�� ���� ��尡 �ǰ� ������ ����.(���� ����) / node_pos�� ������ Ű�� �����ִ� ��尡 �� ���� �ְ� �ȵɼ��� ����.
        int merge_idx = par_node->child[mer_node_pos]->cnt_key; // merge�� ��ü ����ʿ� merge�� Ű ��ġ�� �����Ѵ�.
        par_node->child[mer_node_pos]->key[merge_idx] = par_node->key[mer_node_pos]; //�θ����� Ű�� merge��.
        par_node->child[mer_node_pos]->cnt_key++;

        for (int i = 0; i < par_node->child[node_pos]->cnt_key; i++) { // ����� ��忡�� �� Ű�� ������ �ּ� Ű ���� ������ �ȵ� �� ����. ���� Ű ���� merge�� ���� �Űܾ� ��. ����Ű�� ������ �ƿ� for���� �ȵ��ư�.
            par_node->child[mer_node_pos]->key[merge_idx + 1 + i] = par_node->child[node_pos]->key[i]; // Ű ������ 2�� -> i�� 0, merge idx ������ Ű/ Ű ������ �þ�� i�� �ϳ��� �� �þ. 
            par_node->child[mer_node_pos]->cnt_key++;
        }

        int merge_childidx = par_node->child[mer_node_pos]->cnt_child; //merge�� ��� ���κ����� �Űܾ� �ϴ� ���κ� idx ����.
        for (int i = 0; i < par_node->child[node_pos]->cnt_child; i++) { // ����� ��忡�� Ű�� ����� ���� �ڽ��� ������. �³׸� merge�� ���� �Űܾ� �Ѵ�.
            par_node->child[mer_node_pos]->child[merge_childidx + i] = par_node->child[node_pos]->child[i];
            par_node->child[mer_node_pos]->cnt_child++;
        }

        free(par_node->child[node_pos]); // merge �ǰ� ���� �ݴ��� ���� �ʿ������ �޸𸮿��� ������

        for (int i = mer_node_pos; i < (par_node->cnt_key) - 1; i++) { //�θ� ����� Ű �ϳ��� �̹� �ڽ� ���� ���յǾ����� �������ؾ� ��.
            par_node->key[i] = par_node->key[i + 1];
        }
        par_node->cnt_key--;

        for (int i = mer_node_pos + 1; i < (par_node->cnt_child) - 1; i++) { // �θ� ��忡�� ���� �� �� ���� �� �ڿ� �ٸ� �ڽĵ� ���� �� ������ ��迭 �ؾ� ��. merge�� ��� �� ������ ����� ��.
            par_node->child[i] = par_node->child[i + 1];
        }
        par_node->cnt_child--;
    }
}

// suceessor ã�� �Լ�
int findSuccessor(struct BTreeNode* cur_node) {
    int successor;
    if (cur_node->leaf) { //���� Ž����尡 �����̸�, ã�� �� ����.
        return cur_node->key[0]; //���� ��忡�� ���� ���� Ű �ָ� ��.(successor ����)
    }
    return findSuccessor(cur_node->child[0]); // Ž���� ������ ���� �� �ڽ����� Ž���ؾ� ��.
}


// ���ʿ��� ������ �Լ�
void borrowFromLeft(struct BTreeNode* par_node, int cur_node_pos) { // �θ� ���� ���� ��� pos��ġ�� ���ڷ� ����. �̹� ���� ����� Ű�� ��������. cnt_key�� �ּһ��� Ȥ�� �̸��ϰ���.
    if (par_node->child[cur_node_pos]->leaf) {
        int tenant_idx = 0; // ������ ��ü��忡 �����ִ� Ű�� ������ ��ġ.
        int idx_from_sib_topar = par_node->child[cur_node_pos - 1]->cnt_key - 1;

        for (int i = 0; i < (par_node->child[cur_node_pos]->cnt_key); i++) {
            par_node->child[cur_node_pos]->key[i + 1] = par_node->child[cur_node_pos]->key[i];
        }
        par_node->child[cur_node_pos]->key[tenant_idx] = par_node->child[cur_node_pos - 1]->key[idx_from_sib_topar];
        par_node->child[cur_node_pos]->cnt_key++;
        par_node->child[cur_node_pos - 1]->cnt_key--;

        int successor = findSuccessor(par_node->child[cur_node_pos]);
        par_node->key[cur_node_pos - 1] = successor;
    }
    else {
        int tenant_idx = 0; // ������ ��ü��忡 �����ִ� Ű�� ������ ��ġ.

        // ������ ���� �ڸ��� �����ؾ� �ϱ� ������ �����ִ°Ÿ� ��ĭ �� �ڷ� �̷�� ��.(�����ִ°� ��� ����). borrowFromRight�� �ٸ��� ���� �ڸ� ������ �ؾ� ��.
        for (int i = 0; i < par_node->child[cur_node_pos]->cnt_key; i++) {
            par_node->child[cur_node_pos]->key[i + 1] = par_node->child[cur_node_pos]->key[i];
        }
        par_node->child[cur_node_pos]->key[tenant_idx] = par_node->key[cur_node_pos - 1]; // ������ Ű�� �������� �� �θ𿡰Լ� �����´�. ���⼭�� ���ʿ��� �������ϱ�, cur_node_pos(������ �ڽ� ����Ű�� ��ġ)���� 1�� ���� �θ��� Ű ��ġ�� ��. �׸��� ��������� Ű�� ���� �ö󰡴� ��.
        par_node->child[cur_node_pos]->cnt_key++;

        int idx_from_sib_topar = (par_node->child[cur_node_pos - 1]->cnt_key) - 1; // �θ��� Ű�� ������ �������ϱ� ���� ��� �� ������ Ű�� �ϳ� �θ�� �÷��� ��. 
        par_node->key[cur_node_pos - 1] = par_node->child[cur_node_pos - 1]->key[idx_from_sib_topar]; // �θ���� ������ ��������� Ű�� ���´�. ���⼱ ���� �������.
        par_node->child[cur_node_pos - 1]->cnt_key--;

        // �������� Ű�� ���������� �ڽĵ� ������ �ؾ���. �ڽ� ��ġ ������ ����.(�� ĭ�� ������ �����)
        if (par_node->child[cur_node_pos - 1]->cnt_child > 0) { // ���� ��� �ڽ��� �ִ� ��쿡��
            int tenant_childidx = (par_node->child[cur_node_pos - 1]->cnt_child) - 1; // tenant ��忡�ٰ� ��������� ���� �� �ڽ� ��ġ�� ��ߵǱ� ������ �� �ε��� ����.
            // �ڽ� ��ġ ����. borrowFromRight�� �ٸ��� �ű�� �� �̸� �����ؾ� ��. 
            for (int i = par_node->child[cur_node_pos]->cnt_child; i > 0; i--) { // �ڿ������� �����ؼ� �տ��� �ڷ� �ű�� ����.
                par_node->child[cur_node_pos]->child[i] = par_node->child[cur_node_pos]->child[i - 1];
            }

            par_node->child[cur_node_pos]->child[0] = par_node->child[cur_node_pos - 1]->child[tenant_childidx]; // ���� ��� �ڽ� ������. ������ �ڽ� ���� ��ġ�� ���� ����� 1��° ��ġ.
            par_node->child[cur_node_pos]->cnt_child++;

            par_node->child[cur_node_pos - 1]->cnt_child--;
        }
    }

}

// �����ʿ��� ������ �Լ�
void borrowFromRight(struct BTreeNode* par_node, int cur_node_pos) { // �θ� ���� ���� ��� pos��ġ�� ���ڷ� ����. �̹� ���� ����� Ű�� ��������. cnt_key�� �ּһ��� Ȥ�� �̸��ϰ���.
    if (par_node->child[cur_node_pos]->leaf) {
        int tenant_idx = par_node->child[cur_node_pos]->cnt_key; // ������ ��ü��忡 �����ִ� Ű�� ������ ��ġ.
        int idx_from_sib_topar = 0;
        par_node->child[cur_node_pos]->key[tenant_idx] = par_node->child[cur_node_pos + 1]->key[idx_from_sib_topar];
        par_node->child[cur_node_pos + 1]->cnt_key--;

        for (int i = 0; i < (par_node->child[cur_node_pos + 1]->cnt_key) - 1; i++) {
            par_node->child[cur_node_pos + 1]->key[i] = par_node->child[cur_node_pos + 1]->key[i + 1];
        }
        par_node->child[cur_node_pos + 1]->cnt_key--;

        int successor = findSuccessor(par_node->child[cur_node_pos + 1]);
        par_node->key[cur_node_pos] = successor;
    }
    else {
        int tenant_idx = par_node->child[cur_node_pos]->cnt_key; // ������ ��ü��忡 �����ִ� Ű�� ������ ��ġ.
        par_node->child[cur_node_pos]->key[tenant_idx] = par_node->key[cur_node_pos]; // ������ Ű�� �������� �� �θ𿡰Լ� �����´�. �׸��� ��������� Ű�� ���� �ö󰡴� ��.
        par_node->child[cur_node_pos]->cnt_key++;

        int idx_from_sib_topar = 0;
        par_node->key[cur_node_pos] = par_node->child[cur_node_pos + 1]->key[idx_from_sib_topar]; // �θ���� ������ ��������� Ű�� ���´�.

        // // �������� Ű�� ���������ϱ� ��ġ ������ �ؾ� �Ѵ�.(�� ĭ�� ������ �����)
        for (int i = 0; i < (par_node->child[cur_node_pos + 1]->cnt_key) - 1; i++) {
            par_node->child[cur_node_pos + 1]->key[i] = par_node->child[cur_node_pos + 1]->key[i + 1];
        }
        par_node->child[cur_node_pos + 1]->cnt_key--;


        int idx_from_sib = 0;
        // �������� Ű�� ���������� �ڽĵ� ������ �ؾ���. �ڽ� ��ġ ������ ����.(�� ĭ�� ������ �����)
        if (par_node->child[cur_node_pos + 1]->cnt_child > 0) { // �ڽ��� �ִ� ��쿡��
            int tenant_childidx = par_node->child[cur_node_pos]->cnt_child; // tenant ��忡 ������ �ڽ��� �� ��ġ
            par_node->child[cur_node_pos]->child[tenant_childidx] = par_node->child[cur_node_pos + 1]->child[idx_from_sib]; // ���� ��� �ڽ� ������.
            par_node->child[cur_node_pos]->cnt_child++;

            // �ڽ� ��ġ ���� 
            for (int i = 0; i < par_node->child[cur_node_pos + 1]->cnt_child - 1; i++) {
                par_node->child[cur_node_pos + 1]->child[i] = par_node->child[cur_node_pos + 1]->child[i + 1];
            }
            par_node->child[cur_node_pos + 1]->cnt_child--;
        }
    }
}

void balanceNode(struct BTreeNode* node, int child_pos) { // ���� ���� �ڽĳ�忡���� ��ġ�� ���ڷ� �޴� �Լ�(������,������ ����)
    if (child_pos == 0) { // �ڽĳ�� Ű ��ġ�� �� �����϶��� ������ �θ�,������ ���� ��.
        if (node->child[child_pos + 1]->cnt_key > min_keys) { // (�ڽĳ�� ����) ������ Ű������ �ּҼ��� ���� �� �μ�����
            borrowFromRight(node, child_pos);
        }
        else { // ������ Ű������ �ּҼ��� ���� �μ�����
            mergeNode(node, child_pos + 1, child_pos); // �θ���(������)�� �ڽ� ��ġ�� �ڱ� ���� ��ġ�� ���� �Ѱ���.  
        }
        return;
    }

    else if (child_pos == (node->cnt_key)) { // �ڽĳ�� Ű ��ġ�� �� �������� ���� ���� �θ�, ���� ���� ��.
        if (node->child[child_pos - 1]->cnt_key > min_keys) { // �ڽĳ�� ����, ���� ������ Ű������ �ּҼ��� ���� �� �μ��� ��
            borrowFromLeft(node, child_pos);
        }
        else { // �ּҼ��� ���� �μ��� ��
            mergeNode(node, child_pos, child_pos - 1); // �θ���(������)�� ����� ���� ���մ�� ��� ��ġ�� ���� �Ѱ���.  
        }
        return;
    }
    else { // �� ����,�� ������ ���� �� �̿�
        if (node->child[child_pos - 1]->cnt_key > min_keys) {
            borrowFromLeft(node, child_pos);
        }
        else if (node->child[child_pos + 1]->cnt_key > min_keys) {
            borrowFromRight(node, child_pos);
        }
        else {
            mergeNode(node, child_pos, child_pos - 1); // �شܿ� �ִ� �ڽ� ���� �� �� ������ ��ġ�� ������ ������ ��
        }
        return;
    }
}


// ���� ��忡�� ���� ����� �Լ�
void deleteInnerNode(struct BTreeNode* cur_node, int cur_node_pos) {
    int successor = findSuccessor(cur_node->child[cur_node_pos + 1]); // predecessor Ȥ�� successor�� ���� ��� || merge�� ����� ã�� ���� ���� ����
    cur_node->key[cur_node_pos] = successor;
}


// ���� ����� ���� �־��ָ� ����� �Լ�.
int deleteValFromNode(int val, struct BTreeNode* node) {
    int pos; // ������� ����� ������ ��ġ�� ����.    
    int flag = false; // ���������� ���θ� �˱� ���� flag�� ����
    for (pos = 0; pos < node->cnt_key; pos++) { // val�� ���������ϴ� �� ��ġ�� ã�ƾ� ��.���� ����� Ű ������ŭ Ž��
        if (val == node->key[pos]) { // ���� ����� Ű �迭���� pos�� val�� ������
            flag = true; // ã�Ҵٴ� ǥ��
            break;
        }
        if (val < node->key[pos]) { // Ű �迭�� pos ��ġ ���� val���� ũ�� �� ��ġ���� �����. �ű⿡�� �Ʒ��� �� ���� �Ѵ�.
            break;
        }
    } // �̰� �����ٴ°� �� ��忡�� (�߰� Ž����) pos��ġ�� �������ٴ� �� 
    if (flag) { // flag�� true�̸� ������ �����ϴ� �۾� �ǽ�
        if (node->leaf) {  // �������� �����ؾ� �ϸ�
            for (int i = pos; i < node->cnt_key; i++) { // ����� pos��ġ���� Ű ������ŭ Ž��
                node->key[i] = node->key[i + 1]; // ������� Ű ��ġ�� �� ���� Ű�� �����
            }
            node->cnt_key--;
        }
        else {
            flag = deleteValFromNode(val, node->child[pos + 1]);
            if (node->child[pos + 1]->cnt_key < min_keys) {
                balanceNode(node, pos + 1);
                deleteValFromNode(val, node);
            }
            else { // ���ο��� �����ؾ� �ϸ�
                deleteInnerNode(node, pos); //���� ����� ���� �����ϴ� �Լ� ����. ���� ���� �����忡���� �� ��ġ�� ���ڷ� �ѱ�.
            }
        }
        return flag;
    }
    else { // flag�� false�̸�(������� ���� ��ã�� ��)
        if (node->leaf) { //leaf ����̸�
            return flag;
        }
        else { // ������� ���� �� ã�Ҵµ� ���� ����̸� �� ������.
            flag = deleteValFromNode(val, node->child[pos]); //val�̶� �������� pos��° �ڽ� �Ѱܼ� flag �ޱ�
        }
    }
    if (node->child[pos]->cnt_key < min_keys) { // (��Ͱ� ������ �ٽ� �ö�µ�)����ó���ߴ� �ڽ� ����� Ű ������ �ּҼ��� ���� �μ����� ��
        balanceNode(node, pos); // ������, �����ϴ� �ϴ� �Լ� ���� (���� ���� �ڽĳ���� pos��ġ�� ���ڷ�)
    }

    return flag;
}

// ����� �Լ�
void delete(struct BTreeNode* node, int val) { // ���� ���� ������� ���� ���ڷ� ����.
    if (!node) { // ���� ���� ��忡 �ƿ� ���� ������
        printf("Empty tree!!\n");
        return;
    }
    int flag = deleteValFromNode(val, node); // ���� ��� ������ ���� ����� �Լ� ȣ��. ����� ���̶� ���� ��带 ���ڷ� ����. ������ flag�� ����.
    if (!flag) { // flag�� 0�̸� ����.
        printf("%d does not exist in this tree. \n", val); // �Լ� ������ ��ã���� �÷��װ� 0�ΰŴϱ� ���� �޼��� ���
        return;
    }
    if (node->cnt_key == 0) {  // deleteVal�� �ϰ� ���� node�� Ű������ 0�� �� = ���� ��忡 �ƹ��͵� ��� ��ȭ�� �ʿ���.
        node = node->child[0]; // ���� ��带 ���� ���� �ڽ� ���� ����.
    }
    root = node;

}

/*PRINT******************************************************************************************************/
void printTree(struct BTreeNode* node, int level) {				 // Ʈ�� �׸���
    if (!node) { 											 // empty tree!
        printf("Empty tree!!\n");
        return;
    }
    printf("Level %d :   ", level);
    for (int i = 0; i < level - 1; i++) {
        printf("            ");
    }
    for (int i = 0; i < node->cnt_key; i++) {
        printf("%d ", node->key[i]);
    }
    printf("\n");
    level++;
    for (int i = 0; i < node->cnt_child; i++) {
        printTree(node->child[i], level);
    }
}

void printLeaves(struct BTreeNode* node) {			 // leaf �׸���
    if (!node) { 											 // empty tree!
        printf("Empty tree!!\n");
        return;
    }
    if (node->leaf) {
        for (int i = 0; i < node->cnt_key; i++) {
            printf("%d :", node->key[i]);
            printf("%d ", node->child_data[i]);
        }
        printf("| ");
        if (!node->end_leaf) {
            printLeaves(node->next);
        }
        else {
            printf("\n");
        }
    }
    else {
        printLeaves(node->child[0]);
    }
}

int main(void) {
    insert(1, 6500);
    insert(4, 5000);
    insert(7, 3000);
    insert(10, 2000);
    insert(17, 8000);
    insert(21, 900);
    // insert(31);
    // insert(25);
    // insert(19);
    // insert(20);
    // insert(28);
    // insert(42);

    // delete(root, 21);
    // delete(root, 31);
    // delete(root, 20);
    // delete(root, 10);
    // delete(root, 7);
    // delete(root, 25);
    // delete(root, 42);
    // delete(root, 4);

    // for (int i = 10; i < 100; i += 10) {
    // 	insert(i);
    // }





    printTree(root, 1);
    printLeaves(root);
    printf("----------------------------------------------------------------------------------------------------\n");
    // delete(root, 50);

    printTree(root, 1);
    printLeaves(root);

    searchNode(root, 20);
    searchNode(root, 120);

}