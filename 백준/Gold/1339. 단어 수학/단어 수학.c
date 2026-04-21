#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(int* a, int* b) {
    return *b - *a;
}
int main(void) {
    int n, answer = 0;
    char words[10][9];
    int alph[26], len;

    memset(alph, 0, sizeof(alph));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &words[i]);
        len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            alph[words[i][j] - 'A'] += pow(10, len - j - 1);
        }
    }
    qsort(alph, 26, sizeof(int), cmp);
    for (int i = 0; i < 10; i++) {
        answer += alph[i] * (9 - i);
    }

    printf("%d", answer);
    return 0;
}