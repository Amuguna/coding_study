#include <iostream>
#include <vector>
using namespace std;

int t;
int in;
vector<long> resultF;
vector<long> resultG;

//f(y)는 자연수 y의 모든 약수를 더한 값.
//x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현.
//n이 주어졌을 때 g(n)??

void solutionF(){
    resultF.push_back(1);
    for(int i = 2;i<=1000000;i++){
        long result = 0;
        for(int k = 1; k<=i;k++)
        {
            if(i%k==0)
            {
                result+=k;
            }
        }
        cout << i << endl;
        //cout << result << endl;
        resultF.push_back(result);
    }
    cout << "after "<<endl;
}

void solutionG(){
    resultG.push_back(1);
    for(int i = 1;i<=1000000;i++){
        resultG.push_back(resultG[i-1]+resultF[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solutionF();
    solutionG();
    cin >> t;
    for(int i = 0; i<t;i++){
        cin >> in;
        cout << resultG[in-1] << '\n';
    }
    return 0;
}