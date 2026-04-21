#include <iostream>
#include <queue>
using namespace std;

int N, M;
int T, ans, cnt;
int map[301][301];
int melt[301][301];
bool visit[301][301];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

void init() {
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = false;
            melt[i][j] = 0;
        }
    }
}
void melting() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] <= 0) continue;

            for (int k = 0; k < 4; k++) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                if (map[ni][nj] <= 0) {
                    melt[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] <= 0) continue;
            map[i][j] -= melt[i][j];
        }
    }
}
void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y,x });
    cnt++;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visit[ny][nx]) continue;
            if (map[ny][nx] <= 0) continue;
            visit[ny][nx] = true;
            q.push({ ny,nx });
        }
    }
}
void solution() {
    while (1) {
        T++;
        melting();

        // 빙산 개수 세기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visit[i][j]) continue;
                if (map[i][j] <= 0) continue;
                bfs(i, j);
            }
        }
        // 2개 이상인 경우
        if (cnt > 1) {
            ans = T;
            break;
        }
        // 다 녹은 경우
        if (cnt == 0) {
            ans = 0;
            break;
        }
        init();
    }

    cout << ans;
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