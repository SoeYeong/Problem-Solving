#include <iostream>
#include <vector>
using namespace std;

int R, C, T, ans;
int map[50][50];
int tempm[50][50];
int dx[4] = { -1,0,1,0 };   // 위 오 아래 왼
int dy[4] = { 0,1,0,-1 };
vector<int> r;
struct pos {
    int x, y;
};

void spread() {
    vector<pos> dust;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] <= 0) continue;
            dust.push_back({ i, j });
        }
    }

    for (int i = 0; i < dust.size(); i++) {
        int cnt = 0;
        pos now = dust[i];
        for (int j = 0; j < 4; j++) {
            int nx = now.x + dx[j];
            int ny = now.y + dy[j];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (map[nx][ny] == -1) continue;
            cnt++;
            tempm[nx][ny] += map[now.x][now.y] / 5;
        }
        map[now.x][now.y] -= (map[now.x][now.y] / 5) * cnt;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] += tempm[i][j];
            tempm[i][j] = 0;
        }
    }
}
void clean() {
    for (int i = r[0] - 1; i > 0; i--) {
        map[i][0] = map[i - 1][0];
        map[i - 1][0] = 0;
    }
    for (int i = r[1] + 1; i < R - 1; i++) {
        map[i][0] = map[i + 1][0];
        map[i + 1][0] = 0;
    }

    for (int i = 0; i < C - 1; i++) {
        map[0][i] = map[0][i + 1];
        map[R - 1][i] = map[R - 1][i + 1];
        map[0][i + 1] = 0;
        map[R - 1][i + 1] = 0;
    }

    for (int i = 0; i < r[0]; i++) {
        map[i][C - 1] = map[i + 1][C - 1];
        map[i + 1][C - 1] = 0;
    }
    for (int i = R - 1; i > r[1]; i--) {
        map[i][C - 1] = map[i - 1][C - 1];
        map[i - 1][C - 1] = 0;
    }

    for (int i = C - 1; i > 1; i--) {
        map[r[0]][i] = map[r[0]][i - 1];
        map[r[1]][i] = map[r[1]][i - 1];
        map[r[0]][i - 1] = 0;
        map[r[1]][i - 1] = 0;
    }
}
void solve() {
    while (T--) {
        spread();
        clean();
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] > 0) {
                ans += map[i][j];
            }
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) {
                r.push_back(i);
            }
        }
    }

    solve();
    return 0;
}