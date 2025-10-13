#include <iostream>
#define MOD 1000000009

using namespace std;

int T;
int dp[10002][3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;

    for (int i = 4; i < 10001; i++) {
        dp[i][0] = 1;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
        dp[i][2] = (dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }

    int n;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << "\n";
    }

    return 0;
}