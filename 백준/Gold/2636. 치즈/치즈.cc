#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
bool visit[101][101];
int t, cnt, result;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = false;
        }
    }
}
void bfs() {
    // 테두리 빈 공간
    q.push({ 0,0 });
    visit[0][0] = true;
    cnt = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visit[ny][nx]) continue;

            visit[ny][nx] = true;
            if (map[ny][nx]) {
                map[ny][nx] = 0;
                cnt++;
            }
            else {
                q.push({ ny,nx });
            }
        }
    }
    
    if (cnt)
        result = cnt;
}
void solution() {
    while (1) {
        bfs();

        if (cnt == 0)
            break;

        init();
        t++;
    }
    cout << t << "\n";
    cout << result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    solution();

    return 0;
}