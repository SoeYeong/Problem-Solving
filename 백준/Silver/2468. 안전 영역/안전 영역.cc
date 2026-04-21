#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int map[101][101];
bool visit[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int h, ans, cnt;

queue<pair<int, int>> q;
void init() {
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = false;
        }
    }
}
void bfs(int y, int x) {
    q.push({ y, x });
    visit[y][x] = true;
    cnt++;

    while (!q.empty()) {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visit[ny][nx]) continue;
            if (map[ny][nx] <= h) continue;
            visit[ny][nx] = true;
            q.push({ ny,nx });
        }
    }
}
void solution() {
    while (h) {
        h--;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] <= h) continue;
                if (visit[i][j]) continue;
                bfs(i, j);
            }
        }

        ans = max(ans, cnt);
        init();
    }

    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            h = max(h, map[i][j]);
        }
    }

    solution();
    return 0;
}