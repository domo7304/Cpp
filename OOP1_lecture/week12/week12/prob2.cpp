#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

void timer() {
	const char* week[] = { "월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일" };
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

	cout << " " << hour << "시 " << minute << "분 " << second << "초 " << '\n';

}

int main() {
	while (1) {
		timer();
		Sleep(1000);
	}
}