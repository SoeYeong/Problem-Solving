#include <stdio.h>

#define NMAX 201
#define MMAX 21
#define MAX(X,Y) (X > Y ? X : Y)

int N, M;
int d[NMAX], p[NMAX];
int dp[MMAX][NMAX];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &d[i], &p[i]);
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (d[i] <= j) {
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - d[i]] + p[i]);
            }
            dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
        }
    }
    printf("%d", dp[M][N]);

    return 0;
}