#include <stdio.h>
#include <stdbool.h>
#define max(X, Y) (X > Y) ? X : Y
#define MAX 1001

struct node {
    int r, c;
};
struct node queue[MAX * MAX];
int head = 0, tail = 0;

int M, N, ans;
int tmt[MAX][MAX];
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
    struct node temp = queue[head];
    head = (head + 1) % (MAX * MAX);
    return temp;
};
bool isEmpty() {
    return head == tail;
}

void bfs() {
    while (!isEmpty()) {
        struct node now = deque();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (tmt[nr][nc] == -1) continue;
            if (tmt[nr][nc] > 0) continue;

            tmt[nr][nc] = tmt[now.r][now.c] + 1;
            enque(nr, nc);
        }
    }
}
void find() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmt[i][j] == 0) {
                ans = -1;
                return;
            }
            ans = max(ans, tmt[i][j]);
        }
    }
    ans -= 1;
}
int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &tmt[i][j]);
            if (tmt[i][j] == 1) {
                enque(i, j);
            }
        }
    }

    bfs();
    find();
    printf("%d", ans);

    return 0;
}