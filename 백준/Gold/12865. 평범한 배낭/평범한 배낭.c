#include <stdio.h>

#define NMAX 101
#define WMAX 100001
#define MIN(X,Y) (X < Y ? X : Y)
#define MAX(X,Y) (X > Y ? X : Y)

int N, K;
int W[NMAX], V[NMAX];
int dp[NMAX][WMAX];
int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &W[i], &V[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (W[i] <= j) {
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            }
            dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
        }
    }
    printf("%d", dp[N][K]);

    return 0;
}