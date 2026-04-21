// DP
#include <iostream>
#include <algorithm>

#define MAX 501
#define INF 0x7fffffff
using namespace std;

int N;
int dp[MAX][MAX];
int r[MAX], c[MAX];
// recursive (Top-down)
int mem(int i, int j) {
    int ret = 0;
    if (i == j) return 0;
    if (ret == 0) {
        ret = INF;
        for (int k = i; k < j; k++) {
            ret = min(mem(i, k) + mem(k + 1, j) + r[i] * c[k] * c[j], ret);
        }
    }
    return dp[i][j] = ret;
}
// for loop (Bottom-up)
void forLoop() {
    int minn;
    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + r[j] * c[k] * c[i + j]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> r[i] >> c[i];
    }

    //cout << mem(1, N);
    
    forLoop();
    cout << dp[1][N];
    
    return 0;
}