// ��� �Է� �����ʹ� 0���� ū ����
// �ߺ��� ����
// �����ؾ��ϴ� entry�� key, value ��� ���ڶ�� ���� (int)
// block�� size�� ������ ���� ���� ������ �� ��. 
// block size�� �־����� �� �ȿ� �� ���� entry�� �� �� �ִ��� ����Ͽ� B�� ���� ������ ����
// ������ �������� �ʴ� ��� �������� ���
// ���� �� ���� 12byte header�� �ش�. 
// header���� BlockSize, RootBID, Depth �� ������� ����, RootBID, Depth�� ��� ��� update

// 1. block size �� �־� B tree ���� - header�� �����ؾ���
// 2. ������ (key, value)�� �� �Է�
// 3. ������ B+Tree���� key�� �Է����־��� �� (key, value) �� ����ϴ� search ����
// 4. range search �� ����

// ��� output�� file ��������
// Readme �Բ� �Ἥ ����


#include <iostream>
using namespace std;

class BTree{
public:
	Btree(const char* fileName, int blockSize) {

	}

	bool insert(int key, int rid) {
	
	}
	void print() {
	
	}
	int* search(int key) {// point search

	}
	int* search(int startRange, int endRange) {// range search

	}
};

// Test
int main(int argc, char* argv[])
{
	char command = argv[1][0];
	BTree myBtree = new BTree(any parameter);
	switch (command)
	{
	case 'c':
		// create index file
		break;
	case 'i':
		// insert records from [records data file], ex) records.txt
		break;
	case 's':
		// search keys in [input file] and print results to [output file]
		break;
	case 'r':
		// search keys in [input file] and print results to [output file]
		break;
	case 'p':
		// print B+-Tree structure to [output file]
		break;
	}