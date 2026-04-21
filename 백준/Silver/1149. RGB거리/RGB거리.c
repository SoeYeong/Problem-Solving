#include <stdio.h>
#include <stdlib.h>

#define MIN(X,Y) X>Y?Y:X
#define MAX 1001

int N, ans;
int cost[MAX][3];
int dp[MAX][3];
int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    for (int i = 1; i <= N; i++) {
        dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]);
        dp[i][0] += cost[i][0];
        dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]);
        dp[i][1] += cost[i][1];
        dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]);
        dp[i][2] += cost[i][2];
    }

    ans = MIN(dp[N][0], dp[N][1]);
    ans = MIN(ans, dp[N][2]);
    printf("%d", ans);
    return 0;
}