#include <stdio.h>
#include <string.h>

int T;
long long dp[101];
int main() {
    scanf("%d", &T);
    
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for (int i = 6; i < 101; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    int n;
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}
