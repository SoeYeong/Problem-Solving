#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[500][500];
int visit[500][500];
int sum, maxx;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int level, int x, int y) {
    if (level == 4) {
        maxx = max(maxx, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
        if (visit[xx][yy]) continue;
        visit[xx][yy] = 1;
        sum += map[xx][yy];
        dfs(level + 1, xx, yy);
        visit[xx][yy] = 0;
        sum -= map[xx][yy];
    }
}

void except(int x, int y) {
    //ㅗ
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < M) {
        sum = map[x][y] + map[x][y - 1] + map[x][y + 1] + map[x - 1][y];
        maxx = max(maxx, sum);
    }
    //ㅜ
    if (x + 1 < N  && y - 1 >= 0 && y + 1 < M) {
        sum = map[x][y] + map[x][y - 1] + map[x][y + 1] + map[x + 1][y];
        maxx = max(maxx, sum);
    }
    //ㅏ
    if (x - 1 >= 0 && x + 1 < N && y + 1 < M) {
        sum = map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x - 1][y];
        maxx = max(maxx, sum);
    }
    //ㅓ
    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < N) {
        sum = map[x][y] + map[x][y - 1] + map[x + 1][y] + map[x - 1][y];
        maxx = max(maxx, sum);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = 1;
            sum += map[i][j];
            dfs(1, i, j);
            visit[i][j] = 0;
            sum -= map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            except(i, j);
        }
    }

    cout << maxx;
    return 0;
}