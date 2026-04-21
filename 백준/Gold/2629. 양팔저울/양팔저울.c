#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 31
#define WMAX 15001

int N, M, bead;
int weight[NMAX];
int dp[NMAX][WMAX];
char answer;

void solve(int i, int w) {
    if (i > N || dp[i][w]) {
        return;
    }
    dp[i][w] = 1;

    solve(i + 1, w + weight[i]);
    solve(i + 1, abs(w - weight[i]));
    solve(i + 1, w);    
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &weight[i]);
    }

    solve(0, 0);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &bead);

        if (bead >= WMAX) {
            answer = 'N';
        }
        else if (dp[N][bead]) {
            answer = 'Y';
        }
        else {
            answer = 'N';
        }
        printf("%c ", answer);
    }


    return 0;
}