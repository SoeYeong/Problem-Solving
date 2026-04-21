#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char str[51];
    int ans = 0, len, num = 0;
    bool flag = false;

    scanf("%s", &str);
    len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (i == len) {
            if (flag) {
                ans -= num;
            }
            else {
                ans += num;
            }
        }
        if (str[i] == '-') {
            if (flag) {
                ans -= num;
            }
            else {
                ans += num;
            }
            num = 0;
            flag = true;
        }
        else if (str[i] == '+') {
            if (flag) {
                ans -= num;
            }
            else {
                ans += num;
            }
            num = 0;
        }
        else {
            num *= 10;
            num += str[i] - '0';
        }
    }
    printf("%d", ans);
    return 0;
}