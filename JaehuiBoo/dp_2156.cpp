#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 포도주 잔을 선택하면 모두 마셔야 함. 마신 후에는 원위치에 
// 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
// 1~n 까지 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 
// 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 가장 많은 양을 마시도록 

int n;
vector<int> in;
vector<int> dp;

void input(){
    cin >> n;
    in.push_back(0);
    for(int i = 0; i<n; i++)
    {
        int a;
        cin >> a;
        in.push_back(a);
    }
}

void solution(){
    dp.push_back(in[0]);
    dp.push_back(in[1]);
    if(n>1){
        dp.push_back(in[1]+in[2]);
        if(n>2)
        {
            for(int i = 3; i<n+1;i++){
                dp.push_back(max(in[i]+in[i-1]+dp[i-3],in[i]+dp[i-2]));
                dp[i] = max(dp[i], dp[i-1]);
            }
        }
    }
    cout << dp[n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
    return 0;
}