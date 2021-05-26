#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void game(int);
static int gameCnt = 0, win = 0;

int main() {
	int choice;
	srand((unsigned)time(NULL));
	double sTime = clock();

	while (1) {
		cout << "input your choice (0 - rock, 1 - sissors, 2 - papaer, ctrl + z - end) : ";
		cin >> choice;
		if (cin.eof()) break;

		game(choice);
	}

	double eTime = clock();
	cout << "\nEnd the game, total game count : " << gameCnt << '\n';
	cout << "total duration time : " << (eTime - sTime) / 1000 << " seconds\n" <<
		"User win : " << win << '\n';
}

void game(int choice) {
	gameCnt++;
	int computer = rand() % 3;

	if (computer == 0) {
		if (choice == 2) {
			cout << "You are win!" << '\n';
			win++;
		}
		else if (choice == 1) cout << "You are lose.." << '\n';
		else if (choice == 0) cout << "draw" << '\n';
	}
	else if (computer == 1) {
		if (choice == 0) {
			cout << "You are win!" << '\n';
			win++;
		}
		else if (choice == 2) cout << "You are lose.." << '\n';
		else if (choice == 1) cout << "draw" << '\n';
	}
	else if (computer == 2) {
		if (choice == 1) {
			cout << "You are win!" << '\n';
			win++;
		}
		else if (choice == 0) cout << "You are lose.." << '\n';
		else if (choice == 2) cout << "draw" << '\n';
	}
}