#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int dicey, dicex;
int dir;    // 0,1,2,3 : 동, 남, 서, 북
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int map[21][21];
int dice[7] = { 0,1,2,3,4,5,6 };    // 위, 뒤, 오른, 왼, 앞, 아래
int ans;

void updateDice() {
    int d1 = dice[1];
    int d2 = dice[2];
    int d3 = dice[3];
    int d4 = dice[4];
    int d5 = dice[5];
    int d6 = dice[6];

    switch (dir) {
    case 0:
        dice[1] = d4;
        dice[3] = d1;
        dice[6] = d3;
        dice[4] = d6;
        break;
    case 1:
        dice[1] = d2;
        dice[5] = d1;
        dice[6] = d5;
        dice[2] = d6;
        break;
    case 2:
        dice[1] = d3;
        dice[3] = d6;
        dice[6] = d4;
        dice[4] = d1;
        break;
    case 3:
        dice[1] = d5;
        dice[5] = d6;
        dice[6] = d2;
        dice[2] = d1;
        break;
    }
}
void moveDice() {
    int ny = dicey + dy[dir];
    int nx = dicex + dx[dir];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
        dir += 2;
        dir %= 4;
    }

    dicey += dy[dir];
    dicex += dx[dir];
    updateDice();
}
void bfs(int y, int x) {
    bool visit[21][21];
    memset(visit, false, sizeof(visit));

    visit[y][x] = true;
    int num = map[y][x];
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = nowy + dy[i];
            int nx = nowx + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visit[ny][nx] || map[ny][nx] != num) continue;
            visit[ny][nx] = true;
            q.push({ ny,nx });
            cnt++;
        }
    }

    ans += cnt * num;
}
void decideDir() {
    if (map[dicey][dicex] < dice[6]) {
        dir++;
        dir %= 4;
    }
    else if (map[dicey][dicex] > dice[6]) {
        dir += 3;
        dir %= 4;
    }
}
void solution() {
    for (int i = 0; i < K; i++) {
        moveDice();
        bfs(dicey, dicex);
        decideDir();
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    solution();

    return 0;
}