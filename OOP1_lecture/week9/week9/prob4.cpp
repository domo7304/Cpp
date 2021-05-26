#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int responses[100];
	int frequency[16] = { 0 };

	for (int i = 0; i < 100; i++) responses[i] = (rand() % 11) + 5;

	for (int answer = 0; answer < 100; answer++)
		++frequency[responses[answer]];

	cout << "Rating" << setw(17) << "Frequency" << endl;

	for (int rating = 5; rating < 16; rating++)
		cout << setw(6) << rating << setw(17) << frequency[rating] << '\n';
}