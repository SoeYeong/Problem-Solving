#include <stdio.h>

int num[10001];
int main() {

    for (int i = 1; i < 10001; i++) {
        int temp = i;
        int sum = i;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        num[sum] = 1;

    }

    for (int i = 1; i < 10001; i++) {
        if (num[i]) continue;
        printf("%d\n", i);
    }

    return 0;
}