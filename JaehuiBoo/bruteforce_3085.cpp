#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
vector<char> letters;

void input(){
    cin >> l >> c;
    for(int i = 0; i<c;i++)
    {
        char ch;
        cin >> ch;
        letters.push_back(ch);
    }
}

bool find(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
    else
        return false;
}

void repeat(int index, int a, int b, string result){
    if(result.size()==l)
    {
        if(a>=1 && b >=2)
        {
            cout << result << '\n';
        }
    }
    else{
        for(int i = index+1; i<letters.size();i++)
        {
            if(find(letters[i]))
                repeat(i,a+1,b,result+letters[i]);
            else
                repeat(i,a,b+1,result+letters[i]);
        }
    }

}

void solution(){
    sort(letters.begin(),letters.end());
    int a = 0; //모음 개수 
    int b = 0; //자음 개수 
    repeat(-1,a,b,"");
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
    return 0;
}