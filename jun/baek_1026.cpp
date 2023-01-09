#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> a_arr;
vector<int> b_arr;
bool cmp(int a, int b) {
	return a > b;
}
void input() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		a_arr.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		b_arr.push_back(tmp);
	}
}

void solution() {
	sort(a_arr.begin(), a_arr.end());
	sort(b_arr.begin(), b_arr.end(), cmp);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (a_arr[i] * b_arr[i]);
	}
	cout << ans;
}
int main() {
	input();
	solution();
}