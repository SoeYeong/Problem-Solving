#include <stdio.h>
#include <string.h>

char str[101];
char op_stack[101], stack[101];
int top = -1;

void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int priority(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

int main() {
    scanf("%s", &str);

    for (int i = 0; i < strlen(str); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            printf("%c", str[i]);
        }
        else if (str[i] == '(') {
            push(str[i]);
        }
        else if (str[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }
            pop();
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(str[i])) {
                printf("%c", pop());
            }
            push(str[i]);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }
    return 0;
}
