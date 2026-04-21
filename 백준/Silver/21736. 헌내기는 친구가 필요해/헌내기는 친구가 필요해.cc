#include <iostream>
#include <queue>
using namespace std;

int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int cnt, x, y;
char map[601][601];
bool visit[601][601];

void bfs() {
    queue<pair<int, int>> q;
    q.push({ y,x });
    visit[y][x] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (map[ny][nx] == 'X') continue;
            if (visit[ny][nx]) continue;
            if (map[ny][nx] == 'P') cnt++;
            visit[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') {
                y = i;
                x = j;
            }
        }
    }

    bfs();
    if (cnt == 0) cout << "TT";
    else cout << cnt;

    return 0;
}