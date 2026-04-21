// DP
#include <iostream>
#include <string>
#define MAX 101
using namespace std;

int N, M, K;
long long dp[MAX][MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i < MAX; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (dp[i][j] > 1e9) dp[i][j] = 1e9 + 1;
        }
    }

    if (dp[N][M] < K) {
        cout << -1;
        return 0;
    }

    int t = N + M;
    for (int i = 0; i < t; i++) {
        if (N == 0) {
            cout << 'z';
        }
        else if (M == 0) {
            cout << 'a';
        }
        else if (K <= dp[N - 1][M]) {
            cout << 'a';
            N--;
        }
        else {
            cout << 'z';
            K -= dp[N - 1][M];
            M--;
        }
    }

    return 0;
}