#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int N;
int map[MAX][MAX];
int dr[3] = { 0,1,1 };  // 가로, 세로, 대각선
int dc[3] = { 1,0,1 };

void dfs(int x, int y, int dir) {
    map[x][y]++;

    if (dir == 0 || dir == 2) {
        if (y + 1 < N && map[x][y + 1] != -1) {
            dfs(x, y + 1, 0);
        }
    }
    if (dir == 1 || dir == 2) {
        if (x + 1 < N && map[x + 1][y] != -1) {
            dfs(x + 1, y, 1);
        }
    }
    if (x + 1 < N && y + 1 < N && map[x][y + 1] != -1 && map[x + 1][y] != -1 && map[x + 1][y + 1] != -1) {
        dfs(x + 1, y + 1, 2);
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                map[i][j] = -1;
            }
        }
    }

    dfs(0, 1, 0);
    if (map[N - 1][N - 1] == -1)
        map[N - 1][N - 1] = 0;
    printf("%d", map[N-1][N-1]);
    return 0;
}