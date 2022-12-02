#include <iostream>
#include <math.h>
using namespace std;
int T, N;
//소수들은 채로 거르고 약수 처리에 사용x
int decimal[1000001] = {0, };
void che() {
	for (int i = 2; i < 1000001; i++) {
		bool found = false;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				found = true;
				break;
			}
		}
		if (!found) {
			decimal[i] = 1;
		}
	}
}
int f_func(int x) {
	int sum = 0;
	if (decimal[x] == 1) {
		if (x == 1) {
			return 1;
		}
		else {
			return 1 + x;
		}
	}
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			sum += i;
		}
	}
	return sum;
}
void g_func(int y) {
	int ans = 0;
	for (int j = 1; j <= y; j++) {
		ans += f_func(j);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	che();
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		g_func(N);
	}
}