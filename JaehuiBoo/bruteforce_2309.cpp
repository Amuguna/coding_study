#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> in;
int sum = 0;

void input(){
    for(int i = 0; i<9;i++)
    {
        int a;
        cin >> a;
        in.push_back(a);
        sum +=a;
    }
    cout << "Input Over" << '\n';
}

void solution(){
    sort(in.begin(),in.end());
    sum = sum-100;
    int prevIndex = 0;
    for(int i=in.size()-1;i>0;i--)
    {
        for(int j = prevIndex; j<i;j++){
            if(in[i]+in[j]==sum)
            {
                in.erase(in.begin()+i);
                in.erase(in.begin()+j);
                break;
            }
            else if(in[i]+in[j]>sum)
            {
                prevIndex = j;
                break;
            }
        }
        if(in.size()==7)
            break;
    }
    for(int i = 0; i<in.size();i++)
        cout << in[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
}