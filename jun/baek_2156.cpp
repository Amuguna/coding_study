#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int wine[10001];
int N;

void input() {
  cin >> N;
  for(int i=1;i<=N;i++) {
    cin >> wine[i];
  }
}
void solution() {
  input();
  int ans=0;
  dp[0] = 0;
  dp[1] = wine[1];
  dp[2] = dp[1] + wine[2];
  ans = dp[2];
  for(int i=3;i<=N;i++) {
    int max_val = 0;
    int a = dp[i-3] + wine[i-1] + wine[i];
    int b = dp[i-2] + wine[i];
    int c = dp[i-1];
    max_val = max(max_val, a);
    max_val = max(max_val, b);
    max_val = max(max_val, c);
    dp[i] = max_val;
    ans = max(ans, dp[i]);
  }
  cout << ans;
}

int main() {
  solution();
}
