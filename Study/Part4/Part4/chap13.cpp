#define _CRT_SECURE_NO_WARNINGS

//-----------------------------2020.8.24. 월요일 'Template' 공부 시작--------------------------------------//
//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0)
//		:xpos(x), ypos(y) {}
//	void ShowPosition() const {
//		cout << "[" << xpos << ", " << ypos << "]" << '\n';
//	}
//};
//
//template <class T>
//void SwapData(T& ref1, T& ref2) {
//	T tmp = ref1;
//	ref1 = ref2;
//	ref2 = tmp;
//}
//
//int main() {
//	Point pos1(3, 4);
//	Point pos2(10, 20);
//	SwapData(pos1, pos2);
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	return 0;
//}

#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int arr1[] = { 10, 20, 30 };
	cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << '\n';
	double arr2[] = { 10.3, 20.4, 30.5 };
	cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << '\n';
	return 0;
}