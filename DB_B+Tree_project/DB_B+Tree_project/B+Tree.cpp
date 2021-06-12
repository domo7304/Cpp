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