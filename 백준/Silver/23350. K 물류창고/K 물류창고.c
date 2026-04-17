#include <stdio.h>

typedef struct Info{
    int p, w;
}info;

int N, M;
info container[10001];
int p_cnt[101];
info stack[101], tmp_stack[101];
int ans = 0;
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &container[i].p, &container[i].w);
        p_cnt[container[i].p]++;
    }

    int front = 0, back = N - 1;
    int idx = -1, tmp_idx = -1;

    for (int p = M; p > 0; p--) {
        while (p_cnt[p] > 0) {
            // 컨테이너 우선순위 확인
            if (container[front].p != p) {
                back++;
                container[back].p = container[front].p;
                container[back].w = container[front].w;
                front++;
                ans += container[back].w;
                continue;
            }

            // 같은 우선순위 중 처음 적재하는 경우
            if (idx == -1 || (idx >= 0 && stack[idx].p != p)) {
                idx++;
                stack[idx].p = container[front].p;
                stack[idx].w = container[front].w;
                front++;
                ans += stack[idx].w;
                p_cnt[p]--;
                continue;
            }

            // 적재 컨테이너와 무게 비교
            if (stack[idx].p == p) {
                // 적재 컨테이너보다 가볍거나 같은 경우
                if (stack[idx].w >= container[front].w) {
                    idx++;
                    stack[idx].p = container[front].p;
                    stack[idx].w = container[front].w;
                    front++;
                    ans += stack[idx].w;
                    p_cnt[p]--;
                    continue;
                }

                // 적재 컨테이너보다 무거운 경우
                while (stack[idx].p == p && stack[idx].w < container[front].w) {
                    tmp_idx++;
                    tmp_stack[tmp_idx].p = stack[idx].p;
                    tmp_stack[tmp_idx].w = stack[idx].w;
                    idx--;
                    ans += tmp_stack[tmp_idx].w;
                }

                idx++;
                stack[idx].p = container[front].p;
                stack[idx].w = container[front].w;
                front++;
                ans += stack[idx].w;

                while (tmp_idx != -1) {
                    idx++;
                    stack[idx].p = tmp_stack[tmp_idx].p;
                    stack[idx].w = tmp_stack[tmp_idx].w;
                    tmp_idx--;
                    ans += stack[idx].w;
                }
                p_cnt[p]--;
            }
        }
    }

    printf("%d", ans);
    return 0;
}