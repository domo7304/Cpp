//#include <iostream>
//using namespace std;
//
//class Dice {
//private:
//	int face;
//public:
//	void roll() {
//		cout << rand() << '\n';
//		face = (rand() % 6) + 1;
//	}
//	int getFace() { return face; }
//};
//
//int main() {
//	srand(time(NULL));
//
//	Dice obj;
//	obj.roll();
//	cout << "주사위 값 : " << obj.getFace() << '\n';
//	obj.roll();
//	cout << "주사위 값 : " << obj.getFace() << '\n';
//}