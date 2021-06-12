//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//const int arraysize = 10;
//void bubblesort(int[]);
//
//int main() {
//	int a[arraysize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
//
//	cout << "data items in original order\n";
//	for (int i = 0; i < arraysize; i++) cout << setw(4) << a[i];
//
//	bubblesort(a);
//
//	cout << "\n\nresult :";
//	for (int k = 0; k < arraysize; k++) cout << setw(4) << a[k];
//	cout << "\n";
//}
//
//void bubblesort(int arr[]) {
//	for (int i = 0; (i < arraysize - 1); i++) {
//		int cnt = 0;
//		for (int j = 0; j < arraysize - 1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				cnt++;
//			}
//		}
//		if (cnt == 0) return;
//		cout << "\ndata items in ascending order\n";
//		for (int j = 0; j < arraysize; j++) cout << setw(4) << arr[j];
//	}
//}
//
//
///*
//	앞에서부터 뒤까지 쭉 갈 거고
//
//	inner for 문에서 앞에꺼가 뒤에꺼보다 크면 서로 자리를 바꿔줘
//
//	돌 때마다 cnt라는 변수를 임의로 만들고 0으로 초기화할 거야. 
//	한 차례 inner for문을 다 돌았는데도 cnt가 0이라는 뜻은 정렬이 완료되었다는 뜻이니깐 바로 return을 해 줘.
//
//
//*/