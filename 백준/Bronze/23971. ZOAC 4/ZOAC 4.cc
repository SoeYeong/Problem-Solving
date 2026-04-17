#include <stdio.h>

int W, H, N, M;
int main() {
    scanf("%d %d %d %d", &H, &W, &N, &M);

    int a = W / (M + 1);
    int b = H / (N + 1);
    if (W % (M + 1)) a++;
    if (H % (N + 1)) b++;

    int ans = a * b;
    printf("%d", ans);

    return 0;
}