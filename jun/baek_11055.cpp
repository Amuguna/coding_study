#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int A[1001];
int N;
void input() {
  cin >> N;
  for(int i=1;i<=N;i++) {
    cin >> A[i];
  }
}
void solution() {
  input();
  int ans=0;
  for(int i=1;i<=N;i++) {
    int max_val=0;
    for(int j=1;j<i;j++) {
      if(A[j] < A[i]) {
        max_val = max(max_val, dp[j]);
      }
    }
    dp[i] = max_val + A[i];
    ans = max(ans, dp[i]);
  }
  cout << ans;
}
int main() {
  solution();
}
