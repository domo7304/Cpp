//#include <iostream>
//#include <ctime>
//using namespace std;
//
//void init();
//bool game();
//
//int main() {	
//	cout << "���ǵ� ������ ������ �����մϴ�. Enter�� ������ ������ ���۵˴ϴ�.";
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
//			cout << "�����Դϴ�!" << '\n';
//		}
//	}
//
//	int eTime = clock();
//
//	cout << "�ҿ�ð� : " << (double)(eTime - sTime) / 1000 << "�� \n";
//	cout << "���� ���� : " << (correct * 100) - (wrong * 150) - ((double)(eTime - sTime) / 1000 * 10) << "�� �Դϴ�." << '\n';
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