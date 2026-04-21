#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

int N, M, ans;
int map[MAX][MAX];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

typedef struct pos {
    int r, c;
}pos;
pos queue[MAX * MAX];
int front, tail;

int empty() {
    if (front == tail) {
        return 1;
    }
    return 0;
}
void push(pos a) {
    queue[tail] = a;
    tail++;
}
pos pop() {
    pos ret = queue[front];
    front++;
    return ret;
}
int bfs() {
    int visit[MAX][MAX];
    memset(visit, 0, sizeof(visit));

    int cnt = 0;
    front = 0, tail = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 2) continue;
            if (visit[i][j]) continue;

            pos now = { i, j };
            push(now);
            visit[i][j] = 1;

            while (!empty()) {
                now = pop();
                pos next;

                for (int k = 0; k < 4; k++) {
                    next.r = now.r + dr[k];
                    next.c = now.c + dc[k];

                    if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= M) continue;
                    if (map[next.r][next.c] != 0) continue;
                    if (visit[next.r][next.c]) continue;
                    visit[next.r][next.c] = 1;
                    push(next);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && visit[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}
void dfs(int cnt) {
    if (cnt == 3) {
        int temp = bfs();
        ans = ans < temp ? temp : ans;
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0) continue;
            map[i][j] = 1;
            dfs(cnt + 1);
            map[i][j] = 0;
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);
    }

    dfs(0);
    printf("%d", ans);

    return 0;
}