#include <iostream>
using namespace std;
int n;
void solution() {
	int one_series = 0;
	int cnt = 1;
	while (1) {
		one_series = one_series*10 + 1;
		one_series %= n;
		if (one_series == 0) {
			break;
		}
		else {
			cnt++;
		}
	}
	cout << cnt << '\n';
}
int main() {
	while (cin >> n) {
		solution();
	}
}