#include <iostream>
#include <string>
using namespace std;

// 정수를 저장하는 큐. 입력으로 주어지는 명령을 처리하는 프로그램 작성 
// switch-case문은 int로 

int n;
string str = "";
int in;
int len = -1;
int pointer = 0;
int q[10000];

void solution(string s, int i){
    if(i!=0)
    {
        len+=1;
        q[len] = i;
    }
    else if(s=="pop"){
        if(len-pointer+1==0)
            cout << -1 << '\n';
        else
        {
            cout << q[pointer]<<'\n';
            pointer++;
        }
    }
    else if(s=="size"){
        cout << len-pointer+1 << '\n';
    }
    else if(s=="empty"){
        if(len-pointer+1==0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    else if(s=="front"){
        if(len-pointer+1==0)
            cout << -1 << '\n';
        else
            cout << q[pointer]<< '\n';
    }
    else if(s=="back"){
        if(len-pointer+1==0)
            cout << -1 << '\n';
        else
            cout << q[len] << '\n';
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