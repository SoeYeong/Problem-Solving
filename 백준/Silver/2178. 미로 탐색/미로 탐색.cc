#include <iostream>
#include <queue>
using namespace std;

int N, M;
string map[101];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
int visit[101][101];

void bfs() {
    queue <pair<int, int>> q;
    q.push({ 0,0 });
    visit[0][0] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextr = now.first + dr[i];
            int nextc = now.second + dc[i];

            if (nextr < 0 || nextr >= N || nextc < 0 || nextc >= M) continue;
            if (map[nextr][nextc] == '0') continue;
            if (visit[nextr][nextc]) continue;

            visit[nextr][nextc] = visit[now.first][now.second] + 1;
            q.push({ nextr,nextc });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    bfs();

    cout << visit[N - 1][M - 1];

    return 0;
}