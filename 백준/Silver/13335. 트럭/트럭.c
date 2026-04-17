#include <stdio.h>

int n, w, L;
int trucks[1001];
int bridge[101001] = { 0, };
int main() {
    scanf("%d %d %d", &n, &w, &L);
    for (int i = 0; i < n; i++) {
        scanf("%d", &trucks[i]);
    }

    int tidx = 0;
    int front = 0, back = w;
    int wsum = 0;
    while (1) {
        if (tidx >= n && wsum == 0) break;

        wsum -= bridge[front];

        if (tidx<n && wsum + trucks[tidx] <= L) {
            bridge[back] = trucks[tidx];
            wsum += bridge[back];
            tidx++;
        }
        else {
            bridge[back] = 0;
        }
        back++;
        front++;
    }

    printf("%d", front);
    return 0;
}