#include <iostream>
#include <cmath>
using namespace std;

double avg(int, int, int);
double standard_deviation(int, int, int, double);

int main() {
	int mid, fin, quiz;
	cout << "Input mid, final, quiz score : ";
	cin >> mid >> fin >> quiz;

	double mean = avg(mid, fin, quiz);
	double sd = standard_deviation(mid, fin, quiz, mean);

	bool flag = true;
	while (flag) {
		cout << "***MENU***" << '\n' <<
			"mean - 1, standard deviation - 2, update - 3, exit - 0" << '\n' <<
			"Select the menu" << '\n';

		int choice;
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "\n--------End the program--------" << '\n';
			flag = false;
			break;
		case 1:
			cout << "calculated mean : " << mean << "\n\n";
			break;
		case 2:
			cout << "calculated standard deviation : " << sd << "\n\n";
			break;
		case 3:
			cout << "Input mid, final, quiz score : ";
			cin >> mid >> fin >> quiz;
			mean = avg(mid, fin, quiz);
			sd = standard_deviation(mid, fin, quiz, mean);
			break;
		}
	}
}

double avg(int n1, int n2, int n3) {
	return (double)(n1 + n2 + n3) / 3;
}

double standard_deviation(int n1, int n2, int n3, double avgNum) {
	return sqrt(((n1 - avgNum) * (n1 - avgNum) + (n2 - avgNum) * (n2 - avgNum) + (n3 - avgNum) * (n3 - avgNum)) / 3);
}