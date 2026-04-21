#include <stdio.h>
#include <stdbool.h>

#define max(X, Y) (X>Y)?X:Y
#define MAX 101

struct node {
    int r, c;
};
struct node queue[MAX * MAX];
int head = 0, tail = 0;

int N, M, K, cnt, ans;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

void push(int r, int c) {
    struct node temp;
    temp.r = r;
    temp.c = c;
    queue[tail] = temp;
    tail = (tail + 1) % (MAX * MAX);
}
struct node pop() {
    struct node temp = queue[head];
    head = (head + 1) % (MAX * MAX);
    return temp;
}
bool isEmpty() {
    return head == tail;
}

void bfs(int r, int c) {
    cnt = 1;
    visit[r][c] = true;
    push(r, c);

    while (!isEmpty()) {
        struct node now = pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
            if (map[nr][nc] == 0) continue;
            if (visit[nr][nc]) continue;

            visit[nr][nc] = true;
            cnt++;
            push(nr, nc);
        }
    }
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        map[r][c] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 0) continue;
            if (visit[i][j]) continue;

            bfs(i, j);
            ans = max(ans, cnt);
        }
    }

    printf("%d", ans);
    return 0;
}