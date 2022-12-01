#include <iostream>  //전처리 지시자

using namespace std; 

int main(){
    // 2와 5로 나눠 쩔어지지 않는 정수 n
    // 1로만 이뤄진 n의 배수의 가장 작은 수의 자리수 
    int in;
    while(cin >> in)
    {
        int remain = 1;
        int num = 1;
        if (in)
        while(true){
            if(remain%in==0)
                break;
            else{
                remain = (remain%in)*10+1;
                num++;
            }
        }
        cout << num << '\n';
    }
    return 0;
}
