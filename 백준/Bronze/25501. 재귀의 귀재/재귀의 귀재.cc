#include <stdio.h>
#include <string.h>

int t, cnt;
char str[1001];
int recursion(const char* s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &str);
        cnt = 0;
        int pal = isPalindrome(str);
        printf("%d %d\n", pal, cnt);
    }
    return 0;
}