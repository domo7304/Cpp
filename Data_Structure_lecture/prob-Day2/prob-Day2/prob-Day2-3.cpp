//#include <iostream>
//using namespace std;
//
//int main() {
//	int M;
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//		int N;
//		cin >> N;
//
//		int* arr = new int[N];
//		for (int j = 0; j < N; j++) {
//			int money;
//			cin >> money;
//			arr[j] = money;
//		}
//
//		int sum_k = 0, sum_j = 0, sum_c = 0;
//		for (int j = 0; j < N; j++) {
//			int num = j % 3;
//
//			if (num == 0) sum_k += arr[j];
//			else if (num == 1) sum_j += arr[j];
//			else if (num == 2) sum_c += arr[j];
//		}
//		cout << sum_k << " " << sum_j << " " << sum_c << endl;
//
//		delete[]arr;
//	}
//	return 0;
//}