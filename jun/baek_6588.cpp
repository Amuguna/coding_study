#include <iostream>
#include <algorithm>
using namespace std;
int check_decimal[1000001];
bool is_decimal(int a) {
	if (check_decimal[a] == 1)
		return true;
	else if (check_decimal[a] == 0)
		return false;
	else {
		for (int j = 2; j < a; j++) {
			if (a % j == 0) {
				check_decimal[a] = 0;
				return false;
			}
		}
		check_decimal[a] = true;
		return true;
	}
}
void solution() {
	fill(check_decimal, check_decimal + 1000001, 2);
	cout << check_decimal[100000];
	while (1) {
		int tmp;
		bool is_wrong = true;
		cin >> tmp;
		//종료 조건
		if (tmp == 0)
			break;
		for (int i = 2; i <= tmp / 2; i++) {
			if (is_decimal(i) && is_decimal(tmp - i)) {
				cout << tmp << " = " << i << " + "	<< tmp - i << '\n';
				is_wrong = false;
				break;
			}
		}
		if(is_wrong)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solution();
}