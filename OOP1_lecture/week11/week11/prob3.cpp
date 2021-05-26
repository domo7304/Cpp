//#include <iostream>
//using namespace std;
//
//static const int ROW = 3;
//static const int COL = 4;
//int (*returnArr(int[][4]))[ROW];
//
//int main() {
//	srand((unsigned)time(NULL));
//	int old_arr[3][4];
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++) old_arr[i][j] = rand() % 101;
//	}
//	cout << "< Before change >\n";
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++) cout << old_arr[i][j] << " ";
//		cout << '\n';
//	}
//	int (*arr)[ROW] = returnArr(old_arr);
//
//	cout << "\n< After change >\n";
//	for (int i = 0; i < COL; i++) {
//		for (int j = 0; j < ROW; j++) cout << arr[i][j] << " ";
//		cout << '\n';
//	}
//}
//
//int(*returnArr(int old_arr[][4]))[ROW]{
//	static int arr[COL][ROW];
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++) arr[j][i] = old_arr[i][j];
//	}
//	return arr;
//}