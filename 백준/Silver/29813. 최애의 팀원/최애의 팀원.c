#include <stdio.h>

int N;
char name[1001][5];
int id[1001];
int check[1001];
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s %d", &name[i], &id[i]);
    }

    int cur = 0;
    for (int i = 0; i < N / 2; i++) {
        check[cur] = 1;
        int next = cur;
        for (int j = 0; j < id[cur]; j++) {
            while (1) {
                next++;
                if (next >= N) next = 0;
                if (!check[next]) break;
            }
        }
        check[next] = 1;
        cur = next + 1;
        while (1) {
            if (cur >= N) cur = 0;
            if (!check[cur]) break;
            cur++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (check[i] == 0) {
            printf("%s", name[i]);
            break;
        }
    }
    return 0;
}