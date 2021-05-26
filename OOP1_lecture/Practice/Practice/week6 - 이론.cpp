//#include <iostream>
//#include <ctime>
//using namespace std;
//
//void init();
//bool game();
//
//int main() {	
//	cout << "스피드 구구단 게임을 시작합니다. Enter를 누르면 게임이 시작됩니다.";
//	getchar();
//	system("cls");
//
//	init();
//}
//
//void init() {
//	int sTime = clock();
//	int correct = 0, wrong = 0;
//
//	for (int i = 0; i < 5; i++) {
//		if (game()) correct++;
//		else {
//			wrong++;
//			cout << "오답입니다!" << '\n';
//		}
//	}
//
//	int eTime = clock();
//
//	cout << "소요시간 : " << (double)(eTime - sTime) / 1000 << "초 \n";
//	cout << "최종 점수 : " << (correct * 100) - (wrong * 150) - ((double)(eTime - sTime) / 1000 * 10) << "점 입니다." << '\n';
//}
//
//bool game() {
//	srand((unsigned)time(NULL));
//	
//	int n1 = rand() % 10 + 1,
//		n2 = rand() % 10 + 1,
//		answer = n1 * n2,
//		input;
//	
//	cout << n1 << " x " << n2 << " = ";
//	cin >> input;
//
//	if (input == answer) return true;
//	else return false;
//}