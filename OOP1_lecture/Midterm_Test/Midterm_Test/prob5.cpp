#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	int aCnt = 0, bCnt = 0, cCnt = 0, dCnt = 0;
	int max = -1;

	for (int i = 0; i < 100; i++) {
		int randNum = rand() % 4;

		switch (randNum) {
		case 0:
			cout << "a" << '\n';
			aCnt++;
			break;
		case 1:
			cout << "b" << '\n';
			bCnt++;
			break;
		case 2:
			cout << "c" << '\n';
			cCnt++;
			break;
		case 3:
			cout << "d" << '\n';
			dCnt++;
			break;
		}
	}
	cout << "a count : " << aCnt << ", b count : " << bCnt << ", c count : "
		<< cCnt << ", d count : " << dCnt << '\n';

	aCnt > max ? max = aCnt : max;
	bCnt > max ? max = bCnt : max;
	cCnt > max ? max = cCnt : max;
	dCnt > max ? max = dCnt : max;

	if (max == aCnt) cout << "[가장 많이 생성된 알파벳은 : a 입니다]" << '\n';
	else if (max == bCnt) cout << "[가장 많이 생성된 알파벳은 : b 입니다]" << '\n';
	else if (max == cCnt) cout << "[가장 많이 생성된 알파벳은 : c 입니다]" << '\n';
	else if (max == dCnt) cout << "[가장 많이 생성된 알파벳은 : d 입니다]" << '\n';
}