#include <iostream>
#include <math.h>
using namespace std;
int T, N;

int dp[1000001] = {0, };
long long g_result[1000001] = {0, };
void che() {
	for (int i = 1; i <= 1000000; i++) {
		for (int j = i; j <= 1000000; j += i) {
			dp[j] += i;
		}
	}
	for (int k = 1; k <= 1000000; k++) {
		g_result[k] = g_result[k - 1] + dp[k];
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	che();
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		cout << g_result[N] << '\n';
	}
}