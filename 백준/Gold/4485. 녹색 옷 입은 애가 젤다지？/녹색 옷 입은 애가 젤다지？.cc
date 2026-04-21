#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 0xfffffff
using namespace std;

int N;
int map[126][126];
int dijk[126][126];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct info {
    int y, x, cost;
};
struct cmp {
    bool operator()(info a, info b) {
        return a.cost > b.cost;
    }
};

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dijk[i][j] = MAX;
        }
    }
}
void dijkstra() {
    init();
    dijk[0][0] = map[0][0];

    priority_queue<info, vector<info>, cmp> pq;
    pq.push({ 0,0,map[0][0] });

    while (!pq.empty()) {
        info now = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (dijk[ny][nx] > dijk[now.y][now.x] + map[ny][nx]) {
                dijk[ny][nx] = dijk[now.y][now.x] + map[ny][nx];
                pq.push({ ny,nx, map[ny][nx] });
            }
        }
    }
}

void solution() {
    int cnt = 1;
    while (1) {
        cin >> N;
        if (N == 0)
            break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        dijkstra();

        cout << "Problem " << cnt << ": ";
        cout << dijk[N - 1][N - 1] << "\n";
        cnt++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}