#include <iostream>
#include <vector>
using namespace std;

int A, B, C;
vector<int> ans;
void input() {
	cin >> A >> B >> C;
}

void solution() {
	ans.push_back((A + B) % C);
	ans.push_back(((A % C) +(B%C))%C);
	ans.push_back((A * B) % C);
	ans.push_back((A % C) * (B % C) % C);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}
int main() {
	input();
	solution();
}