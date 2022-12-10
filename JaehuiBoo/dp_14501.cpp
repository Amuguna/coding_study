#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n+1일째 되는 날 퇴사. 남은 n일동안 최대한 많은 상담. 
// 최대한 많은 상담. 하루에 하나씩 서로 다른 사람의 상담. 
// 상담을 완료하는데 걸리는 시간 Ti, 받을 수 있는 금액 Pi
// 퇴사 전에 할 수 있는 상담의 최대 이익은 1일, 4일, 5일에 상담을 하는 것. 이때, 이익은 10 + 20 + 15 = 45 
// 상담을 적절히 했을 때, 최대 수익. 

int n;
vector<int> in[2];
vector<int> output;
// Ti Pi

void input(){
    cin >> n;
    for(int i = 0; i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        in[0].push_back(a);
        in[1].push_back(b);
        if(0>n-(a+i))
            in[1][i] = 0;
    }
}

void solution(){
    for(int i = 0; i<in[1].size();i++)
    {
        output.push_back(in[1][i]);
        int max = 0;
        for(int k = 0; k<i;k++)
        {
            if(in[0][k]+k<=i)
            {
                if(max<output[k])
                    max = output[k];
            }
        }
        output[i] +=max;
    }
    cout << *max_element(output.begin(),output.end()) << '\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
    return 0;
}