#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 50
int N, M;
int map[MAX][MAX];      // 0: not clean, 1: wall, 2: clean
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int x, y;
int dir;
int ans;

int backDir(int d) {
    switch (d) {
    case 0: return 2;
    case 1: return 3;
    case 2: return 0;
    case 3: return 1;
    }
}

void turn() {
    dir--;
    if (dir < 0) dir = 3;
}

void clean() {
    while (1) {
        // 1. 현재 칸 청소
        if (map[x][y] == 0) {
            map[x][y] = 2;
            ans++;
        }
        int flag = 0;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
            if (map[xx][yy] == 0) {
                flag = 1;
            }
        }

        if (flag) {
            turn();
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
            if (map[xx][yy] == 0) {
                x = xx;
                y = yy;
            }
        }
        else {
            int d = backDir(dir);
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
            if (map[xx][yy] == 1) {
                break;
            }
            x = xx;
            y = yy;
        }
    }
    
}

int main() {
    cin >> N >> M;
    cin >> x >> y >> dir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    clean();
    cout << ans;

    return 0;
}