#include <stdio.h>
#define max(X, Y) (X>Y)?X:Y

int N, ans;
int arr[1001], dp[1001];
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    printf("%d", ans);

    return 0;
}