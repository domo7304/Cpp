#include <iostream>
using namespace std;

bool game(int);

int main() {
	int gameCnt = 0, userWin = 0;
	int choice;

	while (1) {
		cout << "Please input number (0 : rock, 1 : sissors, 2 : paper, ctrl + z : end) : ";
		cin >> choice;
		if (cin.eof()) break;

		if (game(choice)) userWin++;
		gameCnt++;
	}
	cout << "\ngame count is " << gameCnt << " and user win is " << userWin << '\n';
}

bool game(int choice) {
	srand((unsigned int)time(NULL));
	int computer = rand() % 3;

	if (computer == choice) {
		cout << "You are win!" << "\n\n";
		return true;
	}
	else{
		cout << "You are lose.." << "\n\n";
		return false;
	}
}