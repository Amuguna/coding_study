#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int test_n;
int len;
int visited[300][300];
int dir_c[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dir_r[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
void bfs(int pri_row, int pri_col, int dst_row, int dst_col) {
    queue<pair<int, pair<int, int>>> q;
    memset(visited, 0, sizeof(visited));
    q.push(make_pair(0, make_pair(pri_row, pri_col)));
    visited[pri_row][pri_col] = 1;
    while (!q.empty()) {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if (r == dst_row && c == dst_col) {
            cout << cnt << '\n';
            return;
        }
        for (int i = 0; i < 8; i++) {
            int next_r = r + dir_r[i];
            int next_c = c + dir_c[i];
            //out of bound
            if (next_r < 0 || next_c < 0 || next_r >= len || next_c >= len)
                continue;
            if (visited[next_r][next_c] == 0) {
                visited[next_r][next_c] = 1;
                q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
            }
        }
    }
}
void solution() {
    cin >> test_n;
    for (int i = 0; i < test_n; i++) {
        cin >> len;
        int pri_col, pri_row;
        int dst_col, dst_row;
        cin >> pri_row >> pri_col;
        cin >> dst_row >> dst_col;
        bfs(pri_row, pri_col, dst_row, dst_col);
    }
}
int main() {
    solution();
}