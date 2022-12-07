#include <iostream>
using namespace std;

// 이친수: 이진수 중 0으로 시작하지 않고 & 1이 두번 연속 나타나지 않는 수 
// n자리 이친수의 개수. (1<=n<=90)
int n;
long long result = 0; //long long 보다 더 크게. 배열이나 문자열로 받기.

void input(){
    cin >> n;
}

long long fact(int f){
    long long rs = 1;
    for(int i = 1; i<=f;i++)
        rs*=i;
    return rs;
}

void solution(){
    // 재귀?
    if (n==1)
        result = 1;
    else if (n==2)
        result = 1;
    else{
        result = 0;
        //10 그 다음
        n-=2;
        long b = 0;
        //마지막에 1. '0'의 개수: a, '10'의 개수: b, 
        while(n-1-2*b>=0)
        {
            result += fact(n-1-b)/(fact(b)*fact(n-1-2*b));
            b+=1;
            cout << result << '\n';
        }
        cout << endl;
        //마지막에 1이 아님. 1의 개수: a, 2의 개수: b.
        b = 0;
        while(n-2*b>=0)
        {
            result += fact(n-b)/(fact(b)*fact(n-2*b));
            b+=1;
            cout << result << '\n';
        }
        cout << endl;
    }
    cout << result << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << fact(n)<<endl;
    // solution();
    return 0;
}