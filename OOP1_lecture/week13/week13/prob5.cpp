//#include <iostream>
//using namespace std;
//
//class Car {
//private:
//	int speed;
//	int gear;
//public:
//	Car(int speed, int gear) {
//		this->speed = speed;
//		this->gear = gear;
//	}
//	void setSpeed() { speed += gear; }
//	int getSpeed() { return speed; }
//	int getGear() { return gear; }
//};
//
//int main() {
//	Car c1(20, 2);
//	Car c2(15, 3);
//	int time = 1;
//
//	cout << c1.getSpeed() << " " << c2.getSpeed() << '\n';
//
//	while (c1.getSpeed() != c2.getSpeed()) {
//		c1.setSpeed();
//		c2.setSpeed();
//		cout << c1.getSpeed() << " " << c2.getSpeed() << '\n';
//		time++;
//	}
//	cout << "두 자동차가 처음 만나는 시간 : " << time << " seconds \n";
//}