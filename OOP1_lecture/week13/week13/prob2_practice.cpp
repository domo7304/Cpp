#include <iostream>
using namespace std;

int main() {
	string str;
	cout << "����� �������� �Է����ּ��� : ";
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
	for ���� ���� + ��ȣ�� ���� �������� cnt�� ������Ű�ٰ�
	+ �� ������ �Ǹ�, cnt��ŭ for���� �ݺ��Ͽ� result�� ����. 
	power�� 1�� �̸� �����س��� for �� �� ������ 10�� ���Ͽ� �ڸ��� ���ߴ� ���

	i == str.length() ���, ��� ���ڿ��� �� �� ���̹Ƿ�
	���������� �������� ���� ���ڿ��� �����ָ� ��
*/