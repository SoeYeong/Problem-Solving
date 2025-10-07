#include <stdio.h>

#define max(X,Y) (X>Y)?X:Y
#define MAX 501

int N, ans;
int arr[MAX];
int dp[MAX];
int main() {
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        arr[a] = b;
    }

    for (int i = 1; i < MAX; i++) {
        if (arr[i] == 0) continue;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    printf("%d", N - ans);

    return 0;
}