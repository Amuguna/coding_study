#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 4보다 큰 모든 짝수는 두 홀수 소수의 합 으로 나타낼 수 있다. 
// 백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오. 

int in;
vector <int> odds;

void input(){
    cin >> in;
}

void solution(){
    // n = a + b. a와 b는 홀수인 소수. 여러가지 경우 -> b-a가 가장 큰 것을 출력 
    //불가능한 경우, "Golebach's conjecture is wrong." 출력 
    //홀수의 1의 자리: 1, 3, 5, 7 => 가능한 합: 4, 6, 8, 0, 2
    //0: 3+7, 5+5 / 2: 1+1, 5+7 / 4: 1+3, 7+7 / 6: 3+3, 5+1 / 8: 3+5, 1+7

    int a = -1;
    int b = -1;

    for(int i = 3; i<in-2;i+=2)
    {
        bool found = false;
        for(int k = 2; k<=sqrt(i);k++)
        {
            if(i%k==0)
            {
                found = true;
                break;
            }
        }
        if(!found)
            odds.push_back(i);
    }

    int before = 0;
    for(int i = odds.size()-1; i>=0; i--){
        for(int k = before; k<odds[i];k++)
        {
            if(odds[k]+odds[i]==in)
            {
                a = odds[k];
                b = odds[i];
                i = -1;
                break;
            }
            else if(odds[k]+odds[i]>in)
            {
                before = k;
                break;
            }
        }
    }

    if(a == -1 || b == -1)
        cout << "Golebach's conjecture is wrong." << '\n';
    else
        cout << in << " = " << a << " + " << b << '\n';
    odds.clear();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1){
        input();
        if(in==0)
            break;
        else{
            solution();
        }
    }
    
    return 0;
}