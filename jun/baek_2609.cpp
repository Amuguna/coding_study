#include <iostream>
#include <algorithm>
using namespace std;
int a, b;

void input() {
	cin >> a >> b;
}
//�ִ�����
void gcd() {
	int small = min(a, b);
	for (int i = small; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i << '\n';
			return;
		}
	}
}
//�ּҰ����
void lcm() {
	int large = max(a, b);
	int small = min(a, b);
	for (int i = 1;; i++) {
		if ((large * i) % small == 0) {
			cout << large * i << '\n';
			return;
		}
	}
}
int main() {
	input();
	gcd();
	lcm();
}