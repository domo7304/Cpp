//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main() {
//	srand((unsigned)time(NULL));
//	int arr1[100] = { 0 };
//	int arr2[16] = { 0 };
//
//	for (int i = 0; i < 100; i++) arr1[i] = (rand() % 11 + 5);
//
//	for (int i = 0; i < 100; i++) arr2[arr1[i]]++;
//
//	cout << setw(6) << "Rating" << setw(15) << "Frequency" << '\n';
//
//	for (int i = 5; i <= 15; i++) cout << setw(6) << i << setw(15) << arr2[i] << '\n';
//
//	int max = 0;
//	for (int i = 5; i <= 15; i++) if (arr2[i] > max) max = i;
//
//	cout << "���� ���� ������ ���� " << max << "�̰�, ���� Ƚ���� " << arr2[max] << "�Դϴ�." << '\n';
//}