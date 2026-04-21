#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int map[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> area;

void bfs(int x, int y) {
    map[x][y] = 1;
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({ x, y });

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (map[nx][ny]) continue;
            map[nx][ny] = 1;
            cnt++;
            q.push({ nx,ny });
        }
    }

    area.push_back(cnt);
}
void solve() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j]) continue;
            bfs(i, j);
        }
    }

    sort(area.begin(), area.end());
    cout << area.size() << "\n";
    for (auto n : area) {
        cout << n << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x1, y1, x2, y2;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                map[y][x] = 1;
            }
        }
    }

    solve();

    return 0;
}