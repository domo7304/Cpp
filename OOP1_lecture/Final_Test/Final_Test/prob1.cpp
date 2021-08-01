//#include <iostream>
//using namespace std;
//
//class vector {
//public:
//	int size;
//	int arr[5];
//};
//
//int main() {
//	vector v1, v2;
//	int size, result = 0;
//	
//	cout << "Input size of vector : ";
//	cin >> size;
//
//	cout << "input vector 1 : ";
//	for (int i = 0; i < size; i++) {
//		int num;
//		cin >> num;
//		v1.arr[i] = num;
//	}
//
//	cout << "input vector 2 : ";
//	for (int i = 0; i < size; i++) {
//		int num;
//		cin >> num;
//		v2.arr[i] = num;
//	}
//
//	cout << "v1 : ( ";
//	for (int i = 0; i < size; i++) {
//		cout << v1.arr[i] << " ";
//	}
//	cout << ")\n";
//
//	cout << "v2 : ( ";
//	for (int i = 0; i < size; i++) {
//		cout << v2.arr[i] << " ";
//	}
//	cout << ")\n";
//
//	cout << "Inner product of v1 and v2 = ";
//	for (int i = 0; i < size; i++) {
//		result += (v1.arr[i] * v2.arr[i]);
//	}
//	cout << result << "\n";
//}