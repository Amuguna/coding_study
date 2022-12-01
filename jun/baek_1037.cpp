#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> arr;
void input() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
}
void solution() {
	sort(arr.begin(), arr.end());
	cout << arr[0] * arr[arr.size() - 1];
}

int main() {
	input();
	solution();
}