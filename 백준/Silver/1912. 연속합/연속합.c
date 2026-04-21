#include <stdio.h>

#define max(X, Y) (X>Y) ? X:Y
#define MAX 100001
#define MIN -100000001

int n;
int arr[MAX];
int ans = MIN;
int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < arr[i] + arr[i - 1]) {
            arr[i] += arr[i - 1];
        }
        ans = max(ans, arr[i]);
    }

    printf("%d", ans);
    return 0;
}