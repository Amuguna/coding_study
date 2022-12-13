#include <iostream>
#include <queue>
#include <string>
using namespace std;
int map[101][101];
int visited[101][101];
int dist[101][101];
int x_dir[4] = { 1, 0, -1, 0 };
int y_dir[4] = { 0, 1, 0,-1 };
int N, M;
int min_ans = 10001;
queue<pair<int, int>> q;
void input() {
    cin >> N >> M;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }
}
void bfs(int x, int y) {
    visited[x][y] = 1;
    q.push(make_pair(x, y));
    dist[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = x + x_dir[i];
            int next_y = y + y_dir[i];
            //out of bound
            if (x < 0 || y < 0 || x >= N || y >= M)
                continue;
            if (map[next_x][next_y] == 1 && visited[next_x][next_y] == 0) {
                dist[next_x][next_y] = dist[x][y] + 1;
                visited[next_x][next_y] = 1;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
    cout << dist[N-1][M-1];
}
int main() {
    input();
    bfs(0, 0);
}
