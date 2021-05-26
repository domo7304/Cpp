//------------------------------------------------2020.7.22. 수요일---------------------------------------------------//
//
//#include <iostream>
//using namespace std;
//
//#define MAX_SPEED 200
//#define FUEL_LOSS 2
//#define ACC_GAIN 10
//#define BRK_GAIN 10
//
//struct Car {
//	char user_id[20];
//	int fuel_guage;
//	int crr_speed;
//};
//
//void CarStat(const Car &car) {
//	cout << "사용자 ID : " << car.user_id << '\n';
//	cout << "현재 연료량 : " << car.fuel_guage << '%' << '\n';
//	cout << "현재 속도 : " << car.crr_speed << "km/h" << '\n' << '\n';
//}
//
//void ACC(Car &car) {
//	if (car.fuel_guage < 2) {
//		cout << "연료를 모두 사용했습니다" << '\n' << '\n';
//		return;
//	}
//	car.fuel_guage -= FUEL_LOSS;
//
//	if (car.crr_speed + ACC_GAIN >= 200) {
//		car.crr_speed = MAX_SPEED;
//		cout << "차량이 최고속도에 도달했습니다" << '\n' << '\n';
//		return;
//	}
//	car.crr_speed += ACC_GAIN;
//}
//
//void BRK(Car &car) {
//	if (car.crr_speed - BRK_GAIN <= 0) {
//		car.crr_speed = 0;
//		cout << "차량이 정지했습니다" << '\n' << '\n';
//		return;
//	}
//	car.crr_speed -= BRK_GAIN;
//}
//
//int main() {
//	Car domo0621 = { "domo0621", 100, 0 };
//	ACC(domo0621);
//	CarStat(domo0621);
//	ACC(domo0621);
//	CarStat(domo0621);
//	ACC(domo0621);
//	CarStat(domo0621);
//	BRK(domo0621);
//	CarStat(domo0621);
//	CarStat(domo0621);
//
//	Car domo7304 = { "domo7304", 3, 50 };
//	ACC(domo7304);
//	CarStat(domo7304);
//	ACC(domo7304);
//	CarStat(domo7304);
//
//	Car rush99 = { "rush99", 100, 10 };
//	ACC(rush99);
//	CarStat(rush99);
//	BRK(rush99);
//	CarStat(rush99);
//	BRK(rush99);
//	CarStat(rush99);
//	BRK(rush99);
//	CarStat(rush99);
//
//	Car rush77 = { "rush77", 4, 195 };
//	ACC(rush77);
//	CarStat(rush77);
//	ACC(rush77);
//	CarStat(rush77);
//
//	return 0;
//}

//------------------------------------------2020.7.23. 목요일--------------------------------------------------//

//#include <iostream>
//using namespace std;
//
//struct Point {
//	int xpos;
//	int ypos;
//
//	void MovePos(int x, int y) {
//		xpos += x;
//		ypos += y;
//	}
//
//	void AddPoint(const Point& pos) {
//		xpos += pos.xpos;
//		ypos += pos.ypos;
//	}
//
//	void ShowPosition() {
//		cout << '[' << xpos << " ," << ypos << ']' << '\n';
//	}
//};
//
//int main() {
//	Point pos1 = { 12, 4 };
//	Point pos2 = { 20, 30 };
//
//	pos1.MovePos(-7, 10);
//	pos1.ShowPosition();
//
//	pos1.AddPoint(pos2);
//	pos1.ShowPosition();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//namespace CAR_CONST{
//	enum {
//		MAX_SPEED = 200,
//		FUEL_LOSS = 2,
//		ACC_GAIN = 10,
//		BRK_GAIN = 10
//	};
//}
//
//struct Car {
//	char user_id[20];
//	int fuel_guage;
//	int crr_speed;
//
//	void CarStat();
//	void ACC();
//	void BRK();
//};
//
//void Car::CarStat() {
//	cout << "사용자 ID : " << user_id << '\n';
//	cout << "현재 연료량 : " << fuel_guage << '%' << '\n';
//	cout << "현재 속도 : " << crr_speed << "km/h" << '\n' << '\n';
//}
//
//void Car::ACC() {
//	if (fuel_guage < 2) {
//		cout << "연료를 모두 사용했습니다" << '\n' << '\n';
//		return;
//	}
//	fuel_guage -= CAR_CONST::FUEL_LOSS;
//
//	if (crr_speed + CAR_CONST::ACC_GAIN >= 200) {
//		crr_speed = CAR_CONST::MAX_SPEED;
//		cout << "차량이 최고속도에 도달했습니다" << '\n' << '\n';
//		return;
//	}
//	crr_speed += CAR_CONST::ACC_GAIN;
//}
//
//void Car::BRK() {
//	if (crr_speed - CAR_CONST::BRK_GAIN <= 0) {
//		crr_speed = 0;
//		cout << "차량이 정지했습니다" << '\n' << '\n';
//		return;
//	}
//	crr_speed -= CAR_CONST::BRK_GAIN;
//}
//
//int main() {
//	Car domo0621 = { "domo0621", 100, 0 };
//	domo0621.ACC();
//	domo0621.CarStat();
//	domo0621.ACC();
//	domo0621.CarStat();
//	domo0621.ACC();
//	domo0621.CarStat();
//	domo0621.BRK();
//	domo0621.CarStat();
//
//	Car domo7304 = { "domo7304", 3, 50 };
//	domo7304.ACC();
//	domo7304.CarStat();
//	domo7304.ACC();
//	domo7304.CarStat();
//
//	Car rush99 = { "rush99", 100, 10 };
//	rush99.ACC();
//	rush99.CarStat();
//	rush99.BRK();
//	rush99.CarStat();
//	rush99.BRK();
//	rush99.CarStat();
//	rush99.BRK();
//	rush99.CarStat();
//
//	Car rush77 = { "rush77", 4, 195 };
//	rush77.ACC();
//	rush77.CarStat();
//	rush77.ACC();
//	rush77.CarStat();
//
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//namespace CAR_CONST {
//	enum {
//		MAX_SPEED = 200,
//		FUEL_LOSS = 2,
//		ACC_GAIN = 10,
//		BRK_GAIN = 10
//	};
//}
//
//class Car {
//private:
//	char user_id[20];
//	int fuel_guage;
//	int crr_speed;
//public:
//	void InitMember(char* ID, int fuel);
//	void CarStat();
//	void ACC();
//	void BRK();
//};
//
//void Car::InitMember(char* ID, int fuel) {
//	strcpy(user_id, ID);
//	fuel_guage = fuel;
//	crr_speed = 0;
//}
//
//void Car::CarStat() {
//	cout << "사용자 ID : " << user_id << '\n';
//	cout << "현재 연료량 : " << fuel_guage << '%' << '\n';
//	cout << "현재 속도 : " << crr_speed << "km/h" << '\n' << '\n';
//}
//
//void Car::ACC() {
//	if (fuel_guage < 2) {
//		cout << "연료를 모두 사용했습니다" << '\n' << '\n';
//		return;
//	}
//	fuel_guage -= CAR_CONST::FUEL_LOSS;
//
//	if (crr_speed + CAR_CONST::ACC_GAIN >= 200) {
//		crr_speed = CAR_CONST::MAX_SPEED;
//		cout << "차량이 최고속도에 도달했습니다" << '\n' << '\n';
//		return;
//	}
//	crr_speed += CAR_CONST::ACC_GAIN;
//}
//
//void Car::BRK() {
//	if (crr_speed - CAR_CONST::BRK_GAIN <= 0) {
//		crr_speed = 0;
//		cout << "차량이 정지했습니다" << '\n' << '\n';
//		return;
//	}
//	crr_speed -= CAR_CONST::BRK_GAIN;
//}
//
//int main() {
//	Car run99;
//	run99.InitMember("run99", 100);
//	run99.ACC();
//	run99.ACC();
//	run99.ACC();
//	run99.CarStat();
//	run99.BRK();
//	run99.CarStat();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Calculator {
//private:
//	int add_cnt;
//	int min_cnt;
//	int mul_cnt;
//	int div_cnt;
//public:
//	void Init();
//	double Add(double num1, double num2);
//	double Min(double num1, double num2);
//	double Mul(double num1, double num2);
//	double Div(double num1, double num2);
//	void ShowOpCount();
//};
//
//void Calculator::Init() {
//	add_cnt = 0;
//	min_cnt = 0;
//	mul_cnt = 0;
//	div_cnt = 0;
//}
//
//void Calculator::ShowOpCount() {
//	cout << "덧셈: " << add_cnt << "뺼셈: " << min_cnt << "곱셈: " << mul_cnt << "나눗셈: " << div_cnt << '\n';
//}
//
//double Calculator::Add(double num1, double num2) {
//	add_cnt++;
//	return num1 + num2;
//}
//
//double Calculator::Min(double num1, double num2) {
//	min_cnt++;
//	return num1 - num2;
//}
//
//double Calculator::Mul(double num1, double num2) {
//	mul_cnt++;
//	return num1 * num2;
//}
//
//double Calculator::Div(double num1, double num2) {
//	div_cnt++;
//	return num1 / num2;
//}
//
//int main() {
//	Calculator cal;
//	cal.Init();
//	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << '\n';
//	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << '\n';
//	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << '\n';
//	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << '\n';
//	cal.ShowOpCount();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Fruitseller {
//private:
//	int APPLE_PRICE;
//	int NumOfApples;
//	int MyMoney;
//
//public:
//	void InitMembers(int price, int num, int money) {
//		APPLE_PRICE = price;
//		NumOfApples = num;
//		MyMoney = money;
//	}
//	int SaleApples(int money) {
//		int num = money / APPLE_PRICE;
//		NumOfApples -= num;
//		MyMoney += money;
//		return num;
//	}
//	void ShowResult() {
//		cout << "남은 사과 : " << NumOfApples << '\n';
//		cout << "판매 수익 : " << MyMoney << '\n';
//	}
//};
//
//class FruitBuyer {
//	int Mymoney;
//	int NumOfApples;
//
//public:
//	void InitMembers(int money) {
//		Mymoney = money;
//		NumOfApples = 0;
//	}
//	void BuyApples(Fruitseller& seller, int money) {
//		NumOfApples = seller.SaleApples(money);
//		Mymoney -= money;
//	}
//	void ShowResult() {
//		cout << "구매한 사과 : " << NumOfApples << '\n';
//		cout << "남은 잔액 : " << Mymoney << '\n';
//	}
//};
//
//int main() {
//	Fruitseller seller;
//	FruitBuyer buyer;
//
//	seller.InitMembers(1000, 20, 0);
//	buyer.InitMembers(5000);
//
//	buyer.BuyApples(seller, 3000);
//
//	cout << "판매자의 상태" << '\n';
//	seller.ShowResult();
//	cout << "구매자의 상태" << '\n';
//	buyer.ShowResult();
//
//	return 0;
//}