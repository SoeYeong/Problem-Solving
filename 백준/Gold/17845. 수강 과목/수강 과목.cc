#include <iostream>
#include <algorithm>

#define KMAX 1001
#define NMAX 10001
using namespace std;

int N, K;
int I[KMAX], T[KMAX];
int dp[KMAX][NMAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> I[i] >> T[i];
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (T[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + I[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    cout << dp[K][N];
    return 0;
}