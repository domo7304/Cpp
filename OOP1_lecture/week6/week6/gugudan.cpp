//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//void intro();
//void playgame();
//bool prob(int);
//
//int main() {
//	intro();
//}
//
//void intro() {
//	cout << "<���ǵ� ������ ����>" << '\n' << "�غ� �Ϸ�Ǹ� enter�� �����ֽñ� �ٶ��ϴ�";
//	getchar();
//	system("cls");
//
//	playgame();
//}
//
//void playgame() {
//	srand((unsigned)time(NULL));
//	int N = 10, correct = 0,
//		rand_num = rand() % 8 + 2,
//		start_time = clock();
//	
//	for (int i = 1; i <= N; i++) {
//		if (prob(i)) correct++;
//	}
//		
//	int end_time = clock();
//
//	cout << "\n�ҿ�� �ð� : " << (double)(end_time - start_time) / 1000 << " seconds \n";
//	cout << "���ھ� : " << 100 * (5 * correct - (double)(end_time - start_time) / 1000) << '\n';
//}
//
//bool prob(int count) {
//	srand((unsigned)time(NULL));
//	int num1 = rand() % 8 + 2,
//		num2 = rand() % 8 + 2,
//		result = num1 * num2,
//		user_input;
//
//	cout << "����" << count << " : " << num1 << " x " << num2 << " = ";
//	cin >> user_input;
//
//	if (user_input == result) return true;
//	else {
//		cout << "�����Դϴ�." << '\n';
//		return false;
//	}
//}