//--------------------------------2020/7/16 È­¿äÀÏ------------------------------------//

//#include <iostream>
//using namespace std;
//
//void Add(int& x) {
//	x += 1;
//}
//
//int main() {
//	int num;
//
//	cin >> num;
//	Add(num);
//
//	cout << num << '\n';
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//void swap(int& x) {
//	x *= -1;
//}
//
//int main() {
//	int num;
//
//	cin >> num;
//	swap(num);
//
//	cout << num << '\n';
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//void SwapPointer(int *ptr1, int *ptr2) {
//	int tmp = *ptr1;
//	*ptr1 = *ptr2;
//	*ptr2 = tmp;
//}
//
//int main() {
//	int num1, num2;
//	cin >> num1 >> num2;
//
//	int* ptr1 = &num1;
//	int* ptr2 = &num2;
//
//	cout << *ptr1 << ' ' << *ptr2 << '\n';
//
//	SwapPointer(ptr1, ptr2);
//	
//	cout << *ptr1 << ' ' << *ptr2<< '\n';
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int& RefFunc1(int& ref) {
//	ref++;
//	return ref;
//}
//
//int main() {
//	int num1 = 1;
//	int& num2 = RefFunc1(num1);
//
//	num1++;
//	num2 += 100;
//	cout << "num1: " << num1 << '\n';
//	cout << "num2: " << num2 << '\n';
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int& RefFunc2(int &ref) {
//	ref++;
//	return ref;
//}
//
//int main() {
//	int num1 = 1;
//	int num2 = RefFunc2(num1);
//
//	num1++;
//	num2 += 100;
//	cout << "num1: " << num1 << '\n';
//	cout << "num2: " << num2 << '\n';
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int RefFunc2(int& ref) {
//	ref++;
//	return ref;
//}
//
//int main() {
//	int num1 = 1;
//	int& num2 = RefFunc2(num1);
//
//	num1++;
//	num2 += 100;
//	cout << "num1: " << num1 << '\n';
//	cout << "num2: " << num2 << '\n';
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int RefFunc2(int& ref) {
//	ref++;
//	return ref;
//}
//
//int main() {
//	int num1 = 1;
//	int num2 = RefFunc2(num1);
//
//	num1++;
//	num2 += 100;
//	cout << "num1: " << num1 << '\n';
//	cout << "num2: " << num2 << '\n';
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//	const int num = 12;
//	const int* ptr = &num;
//	const int* (&ref) = ptr;
//
//	cout << num << '\n';
//	cout << *ptr << '\n';
//	cout << *ref << '\n';
//
//	return 0;
//}