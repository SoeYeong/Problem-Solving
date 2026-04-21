#include <iostream>
#include <algorithm>

#define NMAX 101
#define TMAX 10001
using namespace std;

int N, T;
int K[NMAX], S[NMAX];
int dp[NMAX][TMAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        cin >> K[i] >> S[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            if (K[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    cout << dp[N][T];
    return 0;
}