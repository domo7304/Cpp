//#include <iostream>
//using namespace std;
//
//int main() {
//	char arr1[100] = {};
//	char arr2[100] = {};
//	int arrSize = 100;
//	cin >> arr1;
//
//	int arr2_size = 0;
//	for (int i = 0; i < arrSize; i++) {
//		bool flag = true;
//		for (int j = 0; j < arr2_size; j++) {
//			if (arr2[j] == arr1[i]) flag = false; 
//			// arr[i]�� arr2�� ��� ���� �� 
//			// arr2�� arr1�� ���� ���Ұ� �ִٸ� flag�� false�� �ٲپ� �������� �ʱ�
//		}
//		if (flag == true) {
//			arr2[arr2_size] = arr1[i]; // �ߺ����� �ʴ� ��쿡 ���� ���ڸ� arr2�� ����
//			arr2_size++;
//		}
//	}
//
//	for (int i = 0; i < arr2_size; i++) cout << arr2[i];
//	cout << "\n";
//}