#include <stdio.h>
#include <stdlib.h>

#define MAX 102
#define MOD 1000000000

int N, ans;
int dp[MAX][10];
int main() {
    scanf("%d", &N);
    
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] % MOD;
        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
        dp[i][9] = dp[i - 1][8] % MOD;
    }

    for (int i = 0; i < 10; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }
    printf("%d", ans);
    return 0;
}