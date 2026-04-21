#include <stdio.h>

#define min(X, Y) (X < Y) ? X : Y
#define MAX 1000001

int N;
int dp[MAX];
int main() {
    scanf("%d", &N);

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0) {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }

    }

    printf("%d\n", dp[N]);

    while (N) {
        printf("%d ", N);
        if (N == 1) break;

        if (dp[N - 1] == dp[N] - 1) {
            N -= 1;
        }
        else if (N % 3 == 0 && dp[N / 3] == dp[N] - 1) {
            N /= 3;
        }
        else if (N % 2 == 0 && dp[N / 2] == dp[N] - 1) {
            N /= 2;
        }
    }

    return 0;
}