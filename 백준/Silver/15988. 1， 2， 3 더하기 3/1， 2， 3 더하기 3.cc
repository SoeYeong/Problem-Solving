#include <iostream>

#define MOD 1000000009
using namespace std;

int T, N;
long long dp[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp[i] %= MOD;
    }
    while (T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}