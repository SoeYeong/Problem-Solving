#include <stdio.h>
#include <string.h>

#define MAX 10002

int N, pos;
int stack[MAX];
int main() {
    scanf("%d", &N);

    char cmd[10];
    int tmp;

    for (int i = 0; i < N; i++) {
        scanf("%s", &cmd);

        if (strcmp(cmd, "push") ==0) {
            scanf("%d", &tmp);
            pos++;
            stack[pos] = tmp;
        }
        else if (strcmp(cmd, "pop")==0) {
            if (pos) {
                printf("%d\n", stack[pos]);
                pos--;
            }
            else {
                printf("-1\n");
            }
        }
        else if (strcmp(cmd, "size")==0) {
            printf("%d\n", pos);
        }
        else if (strcmp(cmd, "empty") ==0) {
            if (pos) printf("0\n");
            else printf("1\n");
        }
        else if (strcmp(cmd, "top")==0) {
            if (pos) printf("%d\n", stack[pos]);
            else printf("-1\n");
        }
    }

    return 0;
}