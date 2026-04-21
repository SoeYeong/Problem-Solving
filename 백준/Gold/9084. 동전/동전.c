#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X,Y) (X>Y?X:Y)
#define MMAX 10001
#define NMAX 21

int T, N, M;
int coins[NMAX];
int dp[MMAX];
void solution() {
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = coins[i]; j <= M; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    printf("%d\n", dp[M]);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &coins[i]);
        }
        scanf("%d", &M);
        memset(dp, 0, sizeof(dp));
        solution();
    }
    return 0;
}