#include <stdio.h>

#define MAX 5001

int N, K;
int check[MAX] = { 0, };
int main() {
    scanf("%d %d", &N, &K);
    int cur = K;

    printf("<%d", cur);
    check[cur] = 1;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < K; j++) {
            while (1) {
                cur++;
                if (cur > N) cur = 1;
                if (!check[cur]) break;
            }
        }
        printf(", %d", cur);
        check[cur] = 1;
    }
    printf(">");

    return 0;
}