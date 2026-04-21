#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char s[1000], t[1000];

int main(void) {
    scanf("%s %s", &s, &t);

    int ans = 1;
    int slen = strlen(s);
    int tlen = strlen(t);
    bool reverse = false;
    int fidx = 0, tidx = tlen - 1;

    while (1) {
        if (tlen == slen) {
            break;
        }
        if (reverse) {
            if (t[fidx] == 'B') {
                reverse = false;
            }
            fidx++;
        }
        else {
            if (t[tidx] == 'B') {
                reverse = true;
            }
            tidx--;
        }
        tlen--;
    }

    int ss = reverse ? tidx : fidx;
    int d = reverse ? -1 : 1;
    for (int i = 0; i < slen; i++) {
        if (s[i] != t[ss]) {
            ans = 0;
            break;
        }
        ss += d;
    }

    printf("%d", ans);
    return 0;
}