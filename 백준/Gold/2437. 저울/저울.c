#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int n, sum;
int arr[1000];
int cmp(int* a, int* b) {
    if (*a < *b)
        return -1;
    return 1;
}
int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        if (arr[i] > sum + 1) {
            break;
        }
        sum += arr[i];
    }
    printf("%d", sum + 1);
    return 0;
}