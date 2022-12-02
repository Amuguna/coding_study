#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int a, b;
vector <int> odds;
int result1 = 1; 

void input(){
    cin >> a >> b;
}

void solution(){
    int min = 0;
    if(a<b)
        min = a;
    else
        min = b;
    for(int i = 2; i<=min;i++){
        bool found = false;
        for(int k = 2; k<=sqrt(i);k++)
        {
            if(i%k==0){
                found = true;
                break;
            }
        }
        if(!found)
            odds.push_back(i);
    }
    //odds 에는 min보다 작은 소수들이 들어있다. 
    for(int i = 0; i<odds.size();i++)
    {
        while(1){
            if(a%odds[i]==0 && b%odds[i]==0){
                result1 *=odds[i];
                a/=odds[i];
                b/=odds[i];
            }
            else
                break;
        }
    }
    cout << result1 << '\n';
    cout << result1*a*b << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
    return 0;
}