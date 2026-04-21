#include <stdio.h>
#include <string.h>
#define max(X, Y) (X>Y)?X:Y
#define MAX 100001

int T, n, ans;
int stck[2][MAX];
int dp[2][MAX];
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(stck, 0, sizeof(stck));
        memset(dp, 0, sizeof(dp));
        ans = 0;

        scanf("%d", &n);
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &stck[i][j]);
            }
        }

        dp[0][1] = stck[0][1];
        dp[1][1] = stck[1][1];
        for (int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[1][i - 1] + stck[0][i], dp[1][i - 2] + stck[0][i]);
            dp[1][i] = max(dp[0][i - 1] + stck[1][i], dp[0][i - 2] + stck[1][i]);
        }

        ans = max(dp[0][n], dp[1][n]);
        printf("%d\n", ans);
    }

    return 0;
}