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
//			// arr[i]와 arr2의 모든 원소 비교 
//			// arr2에 arr1과 같은 원소가 있다면 flag를 false로 바꾸어 저장하지 않기
//		}
//		if (flag == true) {
//			arr2[arr2_size] = arr1[i]; // 중복되지 않는 경우에 대해 문자를 arr2에 저장
//			arr2_size++;
//		}
//	}
//
//	for (int i = 0; i < arr2_size; i++) cout << arr2[i];
//	cout << "\n";
//}