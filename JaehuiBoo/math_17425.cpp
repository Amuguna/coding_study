#include <iostream>
#include <vector>
using namespace std;

int t;
int in;
long resultF[1000001];
long resultG[1000001];

//f(y)는 자연수 y의 모든 약수를 더한 값.
//x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현.
//n이 주어졌을 때 g(n)??

void solutionF(){ //배수 이용해서 누적합 
    for(int i = 1;i<=1000000;i++)
    {
        for(int k = i; k<=1000000;k+=i){
            resultF[k]+=i;
        }
    }
}

void solutionG(){
    for(int i = 1;i<=1000000;i++){
        resultG[i] = resultG[i-1]+resultF[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solutionF();
    solutionG();
    cin >> t;
    for(int i = 0; i<t;i++){
        cin >> in;
        cout << resultG[in] << '\n';
    }
    return 0;
}