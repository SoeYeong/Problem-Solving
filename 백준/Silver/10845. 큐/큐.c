#include <stdio.h>
#include <string.h>

int N;
char cmd[10];
int q[10001], f, b;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", &cmd);

        if (strcmp(cmd, "push") == 0) {
            int tmp;
            scanf("%d", &tmp);
            q[b++] = tmp;
        }
        else if (strcmp(cmd, "pop") == 0) {
            if (f == b) printf("-1\n");
            else {
                printf("%d\n", q[f++]);
            }
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", b - f);
        }
        else if (strcmp(cmd, "empty") == 0){
            if (f == b) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(cmd, "front") == 0) {
            if (f == b) printf("-1\n");
            else printf("%d\n", q[f]);
        }
        else if (strcmp(cmd, "back") == 0) {
            if (f == b) printf("-1\n");
            else printf("%d\n", q[b-1]);
        }
    }
    return 0;
}