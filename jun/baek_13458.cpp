#include <iostream>
#include <vector>
using namespace std;
vector<int> A;
int N, B, C;
void input() {
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> B >> C;
}
void solution() {
    long long ans = N;
    for (int i = 0; i < N; i++) {
        A[i] -= B;

        if (A[i] <= 0) {
            continue;
        }
        //�������� ���� ��
        if (A[i] % C != 0) {
            ans += ((A[i] / C) + 1);
        }
        //������ ���� ��
        else {
            ans += (A[i] / C);
        }
    }

    cout << ans;
}
int main() {
    input();
    solution();
}