#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 51

struct node {
    int r, c;
};
struct node queue[2500];
int head = 0, tail = 0;

int w, h, cnt;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dr[8] = { 0,0,-1,1,-1,-1,1,1 };
int dc[8] = { -1,1,0,0,-1,1,-1,1 };

void push(int r, int c) {
    struct node temp;
    temp.r = r;
    temp.c = c;
    queue[tail] = temp;
    tail = (tail + 1) % 2500;
}
struct node pop() {
    struct node temp = queue[head];
    head = (head + 1) % 2500;
    return temp;
}
int isEmpty() {
    if (head == tail)
        return 1;
    return 0;
}

void bfs(int r, int c) {
    visit[r][c] = true;
    push(r, c);

    while (!isEmpty()) {
        struct node now = pop();

        for (int i = 0; i < 8; i++) {
            struct node next;
            next.r = now.r + dr[i];
            next.c = now.c + dc[i];

            if (next.r < 0 || next.r >= h || next.c < 0 || next.c >= w) continue;
            if (map[next.r][next.c] == 0) continue;
            if (visit[next.r][next.c]) continue;
            visit[next.r][next.c] = true;
            push(next.r, next.c);
        }
    }

    cnt++;
}
int main() {
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) {
            break;
        }

        // initialize
        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));

        // input map
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        
        // bfs
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 0) continue;
                if (visit[i][j]) continue;
                bfs(i, j);
            }
        }
        printf("%d\n", cnt);

    }

    return 0;
}