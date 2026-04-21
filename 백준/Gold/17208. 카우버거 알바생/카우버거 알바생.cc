#include <stdio.h>

#define NMAX 101
#define MMAX 301
#define MAX(X,Y) (X > Y ? X : Y)

int N, M, K;
int x[NMAX], y[NMAX];
int dp[NMAX][MMAX][MMAX];
int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= K; k++) {
                if (x[i] <= j && y[i] <= k)
                    dp[i][j][k] = MAX(dp[i - 1][j][k], dp[i - 1][j - x[i]][k - y[i]] + 1);
                dp[i][j][k] = MAX(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }
    printf("%d", dp[N][M][K]);

    return 0;
}