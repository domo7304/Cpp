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
//
//		for (int j = 0; j < N; j++) {
//			int num;
//			cin >> num;
//			arr[j] = num;
//		}
//
//		int sum_k = 0, sum_j = 0, sum_c = 0;
//		int cnt_k = 0, cnt_j = 0, cnt_c = 0;
//		int avg_k = 0, avg_j = 0, avg_c = 0;
//
//		for (int j = 0; j < N; j++) {
//			if ((j % 3 == 0) && arr[j] != 0) {
//				sum_k += arr[j];
//				cnt_k++;
//			}
//			else if ((j % 3 == 1) && arr[j] != 0) {
//				sum_j += arr[j];
//				cnt_j++;
//			}
//			else if ((j % 3 == 2) && arr[j] != 0) {
//				sum_c += arr[j];
//				cnt_c++;
//			}
//		}
//
//		if (sum_k != 0) avg_k = sum_k / cnt_k;
//		if (sum_j != 0) avg_j = sum_j / cnt_j;
//		if (sum_c != 0) avg_c = sum_c / cnt_c;
//
//		cout << sum_k << " " << sum_j << " " << sum_c << endl;
//		cout << avg_k << " " << avg_j << " " << avg_c << endl;
//	}
//	return 0;
//}