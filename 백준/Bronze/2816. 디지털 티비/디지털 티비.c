#include <stdio.h>
#include <string.h>

int N;
char channel[101][11];
int idx1, idx2;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", &channel[i]);
        if (strcmp(channel[i], "KBS1") == 0)
            idx1 = i;
        if (strcmp(channel[i], "KBS2") == 0)
            idx2 = i;
    }

    int order = idx1 > idx2 ? 1 : 0;
    for (int i = 0; i < idx1; i++) {
        printf("1");
    }
    for (int i = 0; i < idx1; i++) {
        printf("4");
    }
    for (int i = 0; i < idx2 + order; i++) {
        printf("1");
    }
    for (int i = 0; i < idx2 + order - 1; i++) {
        printf("4");
    }

    return 0;
}