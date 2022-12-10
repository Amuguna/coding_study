#include <iostream>
#include <algorithm>
using namespace std;
int dp[16];
int N;
int schedule[16][2];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> schedule[i][0] >> schedule[i][1];
	}
}
/*
void solution() {
	for (int j = N; j > 0; j--) {
		int end = j + schedule[j][0] - 1;
		if (end > N) {
			continue;
		}
		int sum = 0;
		for (int k = j+1; k <= end; k++) {
			sum += dp[k];
		}
		if (sum < schedule[j][1]) {
			dp[j] = schedule[j][1];
			for (int u = j+1; u < end; u++) {
				dp[u] = 0;
			}
		}
	}
	int final_sum = 0;
	for (int i = 1; i <= N; i++) {
		final_sum += dp[i];
	}
	cout << final_sum;
}
*/
void solution() {
	int max_val = 0;
	for (int i = 0; i <= N; i++) {
		dp[i] = max(max_val, dp[i]);
		if (schedule[i][0] + i <= N) {
			dp[schedule[i][0] + i] = max(dp[schedule[i][0] + i], schedule[i][1] + dp[i]);
		}
		max_val = max(max_val, dp[i]);
	}
	cout << max_val;
}
int main() {
	input();
	solution();
}