#include <stdio.h>

int T, N;
int hands[81];
int main() {
    scanf("%d %d", &N, &T);
    for (int i = 0; i < 2 * N; i++) {
        scanf("%d", &hands[i]);
    }

    int idx = 0;
    for (int i = 0; i < T; i++) {
        int b;
        scanf("%d", &b);
        idx = (idx + b - 1) % (2 * N);
        printf("%d ", hands[idx]);
    }
    return 0;
}