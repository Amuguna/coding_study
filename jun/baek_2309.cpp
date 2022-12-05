#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> people;
void input() {
	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		people.push_back(tmp);
	}
}
void solution() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int sum = 0;
			if (i == j) {
				continue;
			}
			else {
				vector<int> ans;
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						sum += people[k];
						ans.push_back(people[k]);
					}
					else {
						continue;
					}

					if (sum == 100 && ans.size() == 7) {
						sort(ans.begin(), ans.end());
						for (int u = 0; u < ans.size(); u++) {
							cout << ans[u] << '\n';
						}
						return;
					}
				}
			}
		}
	}
}

int main() {
	input();
	solution();
}