#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define max(X,Y) (X > Y) ? X : Y
#define MAX 51

struct node {
    int r, c;
};
struct node queue[MAX * MAX];
int head = 0, tail = 0;

int N, M, ans = -1;
char map[MAX][MAX];
int visit[MAX][MAX];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

void enque(int r, int c) {
    struct node temp;
    temp.r = r;
    temp.c = c;
    queue[tail] = temp;
    tail = (tail + 1) % (MAX * MAX);
}
struct node deque() {
    struct node temp;
    temp = queue[head];
    head = (head + 1) % (MAX * MAX);
    return temp;
}
bool isEmpty() {
    return head == tail;
}

void bfs(int r, int c) {
    visit[r][c] = 1;
    enque(r, c);

    while (!isEmpty()) {
        struct node now = deque();
        ans = max(ans, visit[now.r][now.c]);

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (nr < 0 || nr >= N || nc < 0  || nc >= M) continue;
            if (map[nr][nc] == 'W') continue;
            if (visit[nr][nc]) continue;

            visit[nr][nc] = visit[now.r][now.c] + 1;
            enque(nr, nc);
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'W') continue;

            // init
            memset(visit, 0, sizeof(visit));

            // bfs
            bfs(i, j);
        }
    }

    printf("%d", ans - 1);

    return 0;
}