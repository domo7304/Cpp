#include <iostream>
using namespace std;

int main() {
	string str;
	cout << "계산할 덧셈식을 입력해주세요 : ";
	cin >> str;

	int cnt = 0;
	int result = 0;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+') {
			int power = 1;
			for (int j = 0; j < cnt; j++) {
				result += (str[i - j - 1] - '0') * power;
				power *= 10;
			}
			cout << "result : " << result << '\n';
			cnt = 0;
		}
		else if (i == str.length()) {
			int power = 1;
			for (int j = 0; j < cnt; j++) {
				result += (str[i - j - 1] - '0') * power;
				power *= 10;
			}
			cout << "result : " << result << '\n';
			cnt = 0;
		}
		else cnt++;
	}
}

/*
	for 문을 돌며 + 기호를 만날 때까지는 cnt를 증가시키다가
	+ 를 만나게 되면, cnt만큼 for문을 반복하여 result에 저장. 
	power를 1로 미리 지정해놓고 for 문 돌 때마다 10씩 곱하여 자릿수 맞추는 방식

	i == str.length() 라면, 모든 문자열을 다 돈 것이므로
	마지막으로 더해지지 않은 문자열만 더해주면 끝
*/