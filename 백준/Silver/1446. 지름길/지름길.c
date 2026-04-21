#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN(X,Y) X>Y?Y:X

typedef struct road {
    int start, end, cost;
}road;

int cmp(road* a, road* b) {
    if (a->start != b->start) {
        return a->start - b->start;
    }
    return a->end - b->end;
}
int main(void) {
    int n, d;
    scanf("%d %d", &n, &d);

    road* roads = malloc(sizeof(road) * n);
    int* dp = malloc(sizeof(int) * (d + 1));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &roads[i].start, &roads[i].end, &roads[i].cost);
    }
    qsort(roads, n, sizeof(road), cmp);

    for (int i = 0; i <= d; i++) {
        dp[i] = i;
    }

    int idx = 0;
    for (int i = 0; i <= d; i++) {
        if (i > 0) {
            dp[i] = MIN(dp[i], dp[i - 1] + 1);
        }
        while (idx < n && roads[idx].start == i) {
            if (roads[idx].end <= d) {
                dp[roads[idx].end] = MIN(dp[roads[idx].end], dp[i] + roads[idx].cost);
            }
            idx++;
        }
    }

    printf("%d", dp[d]);

    free(roads);
    free(dp);
    return 0;
}