#include <iostream>
#include <queue>
using namespace std;

int N, M;
int pic[501][501];
bool visit[501][501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
priority_queue<int> pq;

void bfs(int y, int x) {
    q.push({ y, x });
    visit[y][x] = true;
    int size = 0;

    while (!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        size++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nexty = ny + dy[i];
            int nextx = nx + dx[i];

            if (nexty < 0 || nexty >= N || nextx < 0 || nextx >= M) continue;
            if (pic[nexty][nextx] == 0) continue;
            if (visit[nexty][nextx]) continue;
            visit[nexty][nextx] = true;
            q.push({ nexty, nextx });
        }
    }

    pq.push(size);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> pic[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (pic[i][j] == 0) continue;
            if (visit[i][j]) continue;
            bfs(i, j);
        }
    }

    cout << pq.size() << "\n";
    if (pq.empty()) {
        cout << 0;
    }
    else {
        cout << pq.top();
    }
    return 0;
}