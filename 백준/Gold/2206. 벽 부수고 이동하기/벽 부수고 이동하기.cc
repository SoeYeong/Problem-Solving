#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

int N, M, answer;
int map[MAX][MAX];
int visit[MAX][MAX][2];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
struct info {
    int r, c, wall;
};

int bfs() {
    queue<info> q;
    q.push({ 1,1,0 });
    visit[1][1][0] = 1;

    while (!q.empty()) {
        info now = q.front();
        q.pop();

        if (now.r == N && now.c == M) {
            return visit[N][M][now.wall];
        }

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
            if (map[nr][nc] == 0 && visit[nr][nc][now.wall] == 0) {
                visit[nr][nc][now.wall] = visit[now.r][now.c][now.wall] + 1;
                q.push({ nr,nc,now.wall });
            }
            else if (map[nr][nc] == 1 && visit[nr][nc][1] == 0) {
                if (now.wall) continue;
                visit[nr][nc][1] = visit[now.r][now.c][now.wall] + 1;
                q.push({ nr,nc,1 });
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    cin >> N >> M;
    string tmp;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        for (int j = 1; j <= M; j++) {
            map[i][j] = tmp[j - 1] - '0';
        }
    }

    // bfs
    answer = bfs();
    cout << answer;

    return 0;
}