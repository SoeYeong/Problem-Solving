#include <stdio.h>

#define MOD 15746
#define MAX 1000001

int N;
int dp[MAX];
int main() {
    scanf("%d", &N);

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    printf("%d", dp[N]);
    return 0;
}