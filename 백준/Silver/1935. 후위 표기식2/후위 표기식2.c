#include <stdio.h>
#include <string.h>


int N;
char arr[101];
int num[27];
double stack[101];
int main() {
    scanf("%d", &N);
    scanf("%s", &arr);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    int back = -1;
    double tmp1, tmp2;
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            stack[++back] = (double)num[arr[i] - 'A'];
        }
        else if (arr[i] == '-') {
            tmp2 = stack[back--];
            tmp1 = stack[back--];
            stack[++back] = tmp1 - tmp2;
        }
        else if (arr[i] == '+') {
            tmp2 = stack[back--];
            tmp1 = stack[back--];
            stack[++back] = tmp1 + tmp2;
        }
        else if (arr[i] == '*') {
            tmp2 = stack[back--];
            tmp1 = stack[back--];
            stack[++back] = tmp1 * tmp2;
        }
        else if (arr[i] == '/') {
            tmp2 = stack[back--];
            tmp1 = stack[back--];
            stack[++back] = tmp1 / tmp2;
        }
    }

    printf("%.2lf", stack[0]);

    return 0;
}
