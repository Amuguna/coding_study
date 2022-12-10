#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 수열 a에서 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램
// 첫째 줄에 수열 a의 크기 n (1~1000)
// 둘째 줄에 수열을 이루고 있는 ai가 주어진다.

int n;
vector<int> in;
vector<int> dp;
int m = 0;

void input(){
    cin >> n;
    for(int i = 0; i<n;i++){
        int a;
        cin >> a;
        in.push_back(a);
    }
}


void solution(){
    for (int i = 0; i<n;i++){
        dp.push_back(in[i]);
        if(i!=0){
            m=0;
            for(int k = i-1; k>=0; k--)
            {
                if(in[k]<in[i] && dp[k]>m)
                {
                    m = dp[k];
                }
            }
            dp[i] +=m;
        }
    }
    cout << *max_element(dp.begin(),dp.end()) << '\n';


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
    return 0;
}