#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n; //n: even int input. n은 두 홀수 소수의 합으로 나타낼 수 있다. 
vector<int> odds;
int a, b;

//output: n = a + b (a, b는 두 홀수 소수. b-a가 가장 큰 것을 출력).
//나타낼 수 없는 경우 "Goldbach's conjecture is wrong" 출력 

void input(){
    cin >> n;
}

void gettingOdds(){
    for(int i = 3;i<1000000;i+=2)
    {
        bool in = true;
        for(int j = 3; j<=sqrt(i);j+=2){
            if(i%j==0)
            {
                in = false;
                break;
            }
        }
        if(in)
            odds.push_back(i);
    }
}

void solution(){
    //포인터 두개를 사용하여 한개는 index 0~, 나머지 한개는 index size-1 ~ 돈다
    //작았다가 -> 커지는 그 지점을 찾기.  
    int index = 0;
    while(odds[index]<n){
        index++;
    }
    index-=1;
    
    bool find = false;
    int prevIndex = 0;
    int result = 0;
    for(int i = index;i>=0;i--)
    {
        for(int j = prevIndex;j<=i;j++)
        {
            result = odds[i]+odds[j];
            if(result==n)
            {
                find = true;
                a = odds[j];
                b = odds[i];
                break;
            }
            if(result>n)
            {
                prevIndex = j;
                break;
            }
        }
        if(result<n || find){
            break;
        }
    }
    if(!find)
        cout << "Goldbach" << '\n';
    else
        cout << n << " = " << a << " + " << b << '\n';
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    gettingOdds();

    n = -1;
    while(1){
        a = -1;
        b = -1;
        input();
        if(n==0)
            break;
        solution();
    }
    return 0;
}