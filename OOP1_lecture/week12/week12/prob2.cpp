#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

void timer() {
	const char* week[] = { "������", "ȭ����", "������", "�����", "�ݿ���", "�����", "�Ͽ���" };
	int weekday;
	int hour;
	int minute;
	int second;

	second = time(0) % 60;
	minute = time(0) / 60 % 60;
	hour = time(0) / 60 / 60 % 24 + 9;
	weekday = time(0) / 3600 / 24 % 7;

	if (weekday == 0) cout << week[3];
	else if (weekday == 1) cout << week[4];
	else if (weekday == 2) cout << week[5];
	else if (weekday == 3) cout << week[6];
	else if (weekday == 4) cout << week[0];
	else if (weekday == 5) cout << week[1];
	else if (weekday == 6) cout << week[2];

	cout << " " << hour << "�� " << minute << "�� " << second << "�� " << '\n';

}

int main() {
	while (1) {
		timer();
		Sleep(1000);
	}
}