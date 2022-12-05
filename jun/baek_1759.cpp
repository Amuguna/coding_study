#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;
vector<char> word;
void input() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char tmp;
		cin >> tmp;
		word.push_back(tmp);
	}
	sort(word.begin(), word.end());
}
bool check(vector<char> v) {
	int vowel_cnt = 0;
	int consonant_cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			vowel_cnt += 1;
		}
		else {
			consonant_cnt += 1;
		}
	}
	if (vowel_cnt >= 1 && consonant_cnt >= 2)
		return true;
	else
		return false;
}
void back_track(int cnt, int index, vector<char> ans) {
	if (cnt > L) {
		if (check(ans)) {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}

	if (index < C) {
		ans.push_back(word[index]);
		back_track(cnt + 1, index + 1, ans);
		ans.erase(ans.begin()+ans.size()-1);
		back_track(cnt, index + 1, ans);
	}
}
void solution() {
	vector<char> answer;
	back_track(1, 0, answer);
}
int main() {
	input();
	solution();
}