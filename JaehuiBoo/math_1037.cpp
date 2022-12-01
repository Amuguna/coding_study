#include <iostream>
#include <vector>

using namespace std;

//a가 n의 진짜 약수.
//진짜 약수는, n이 a의 배수 & a가 1이나 n이 아니어야. 
//입1) 진짜 약수의 개수 
//입2) n의 진짜 약수 

int s;
vector<int> real;

void input(){
    cin >> s;
    for(int i = 0; i<s;i++)
    {
        int a;
        cin >> a;
        real.push_back(a);
    }
}

void solution(){
    int min = 1000000;
    int max = -1;
    for(int i = 0; i<real.size();i++)
    {
        if(real[i]<min)
            min = real[i];
        if(real[i]>max)
            max = real[i];
    }
    cout << min*max << endl;
}

int main(){
    input();
    solution();
}
