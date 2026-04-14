#include <stdio.h>

int x, y;
char days[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
    scanf("%d %d", &x, &y);

    int sum = y;
    for (int i = 0; i < x; i++) {
        sum += mon[i];
    }

    printf("%s", days[sum%7]);
    return 0;
}