#include <stdio.h>

#define min(x, y) (x < y) ? (x) : (y)

int M, N;
char board[51][51];
char bw[8][8] = { "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", 
                  "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB" };
char wb[8][8] = { "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                  "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
int ans = 51 * 51;

void cmp(int r, int c) {
    int sum = 0;
    for (int i = r; i < r + 8; i++) {
        for (int j = c; j < c + 8; j++) {
            if (board[i][j] != bw[i - r][j - c]) sum++;
        }
    }
    ans = min(ans, sum);

    sum = 0;
    for (int i = r; i < r + 8; i++) {
        for (int j = c; j < c + 8; j++) {
            if (board[i][j] != wb[i - r][j - c]) sum++;
        }
    }
    ans = min(ans, sum);
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", &board[i]);
    }

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            cmp(i, j);
        }
    }

    printf("%d", ans);

    return 0;
}