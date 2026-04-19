#include <stdio.h>
#include <string.h>

#define MIN(a, b) (a < b) ? a : b

int N;
int arr[100001][3];
int dp[100001][3];
int main() {
    int t = 1;
    int tmp1, tmp2;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        }

        memset(dp, 0x0f, sizeof(dp));
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][1] + arr[0][2];

        for (int i = 1; i < N; i++) {
            dp[i][0] = MIN(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] += arr[i][0];

            tmp1 = MIN(dp[i][0], dp[i - 1][0]);
            tmp2 = MIN(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = MIN(tmp1, tmp2);
            dp[i][1] += arr[i][1];

            tmp1 = MIN(dp[i][1], dp[i - 1][1]);
            dp[i][2] = MIN(tmp1, dp[i - 1][2]);
            dp[i][2] += arr[i][2];
        }
        printf("%d. %d\n", t, dp[N-1][1]);
        t++;
    }

    return 0;
}
