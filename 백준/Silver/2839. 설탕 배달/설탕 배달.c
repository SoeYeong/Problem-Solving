#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, ans = -1;
    scanf("%d", &N);

    if (N % 5 == 0) {
        ans = N / 5;
    }
    else if (N % 5 == 1 || N % 5 == 3) {
        ans = N / 5 + 1;
    }
    else if (N > 7) {
        ans = N / 5 + 2;
    }
    printf("%d", ans);
    return 0;
}