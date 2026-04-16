#include <stdio.h>

int a, b;
int arr[21] = { 0, };
int main() {
    for (int i = 1; i < 21; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        scanf("%d %d", &a, &b);

        int tmp[21] = {0, };
        for (int j = a; j <= b; j++) {
            tmp[j] = arr[j];
        }

        int k = b;
        for (int j = a; j <= b; j++) {
            arr[j] = tmp[k--];
        }
    }

    for (int i = 1; i < 21; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}