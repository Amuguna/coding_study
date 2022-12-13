#include <iostream>
#include <string>
using namespace std;
int N;
int queue_arr[10000];
int f=0, rear=0;
void push() {
  cin >> queue_arr[rear];
  rear += 1;
}
void pop() {
  if(f == rear) {
    cout << -1 << '\n';
  }
  else {
    cout << queue_arr[f] << '\n';
    f += 1;
  }
}
void size() {
  cout << rear - f << '\n';
}
void empty() {
  if(f == rear) {
    cout << 1 << '\n';
  }
  else {
    cout << 0 << '\n';
  }
}
void front() {
  if(f == rear) {
    cout << -1 << '\n';
  }
  else {
    cout << queue_arr[f] << '\n';
  }
}
void back() {
  if(f == rear) {
    cout << -1 << '\n';
  }
  else {
    cout << queue_arr[rear-1] << '\n';
  }
}
void queue(string command) {
  if(command == "push") {
    push();
  }
  else if(command == "pop") {
    pop();
  }
  else if(command == "size") {
    size();
  }
  else if(command == "empty") {
    empty();
  }
  else if(command == "front") {
    front();
  }
  else if(command == "back") {
    back();
  }
}
int main() {
  cin >> N;
  string command;
  for(int i=0;i<N;i++) {
    cin >> command;
    queue(command);
  }
}
/*
#include<iostream>
#include<queue>
#include<string>
 
using namespace std;
 
int main(void){
 
    int N;
    cin >> N;
 
    queue<int> q;
    int num;
 
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
 
        if(str == "push"){
            int data;
            cin >> data;
            q.push(data);
 
        }else if(str == "pop"){
 
            if(q.size() != 0){
                num = q.front();
                q.pop();
            }else{
                num = -1;
            }
            cout << num << endl;
 
        }else if(str == "size"){
            cout << q.size() << endl;
 
        }else if(str == "empty"){
            if(q.size() == 0) num =1;
            else num =0;
            cout << num << endl;
 
        }else if(str == "front"){
            if(q.size() == 0){
                num = -1;
            }else{
                num = q.front();
            }
            cout << num << endl;
 
        }else if(str == "back"){
            if(q.size() == 0){
                num = -1;
            }else{
                num = q.back();
            }
            cout << num << endl;
        }
 
    }
    return 0;
}
*/
