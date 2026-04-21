#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X,Y) (X>Y?X:Y)
#define CMAX 10001
#define NMAX 101

int N, M, sum;
int app[NMAX], cost[NMAX];
int dp[NMAX][CMAX];
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &app[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &cost[i]);
        sum += cost[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (cost[i] <= j) {
                dp[i][j] = MAX(dp[i][j], dp[i - 1][j - cost[i]] + app[i]);
            }
            dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (dp[N][i] >= M) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}