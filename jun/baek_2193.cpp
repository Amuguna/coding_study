#include <iostream>
#include <vector>
using namespace std;
int N;
long long dp[91];

void input() {
	cin >> N;
}
void solution() {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i - 2; j++) {
			dp[i] += dp[j];
		}
	}
	cout << dp[N];
}
int main() {
	input();
	solution();
}
