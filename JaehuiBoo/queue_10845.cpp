#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 정수를 저장하는 큐. 입력으로 주어지는 명령을 처리하는 프로그램 작성 
// switch-case문은 int로 

int n;
string str = "";
int in;
queue<int> q;

void solution(string s, int i){
    if(i!=0)
        q.push(i);
    else if(s=="pop"){
        if(!q.empty())
        {
            cout << q.front()<<'\n';
            q.pop();
        }
        else
            cout << -1 << '\n';
    }
    else if(s=="size"){
        cout << q.size() << '\n';
    }
    else if(s=="empty"){
        cout << q.empty() << '\n';
    }
    else if(s=="front"){
        if(q.empty())
            cout << -1 << '\n';
        else
            cout << q.front() << '\n';
    }
    else if(s=="back"){
        if(q.empty())
            cout << -1 << '\n';
        else
            cout << q.back() << '\n';
    }
    else
        cout << "WRONG" <<'\n';
}

void input(){
    cin >> n;
    for(int i = 0; i<n;i++)
    {
        in = 0;
        cin >> str;
        if(str=="push")
            cin >> in;
        solution(str, in);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    return 0;
}