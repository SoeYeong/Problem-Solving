#include <iostream>
#include <algorithm>
#include <cstring>

#define NMAX 21
#define MMAX 10001
using namespace std;

int T, N, M;
int coins[NMAX];
int dp[MMAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> coins[i];
        }
        cin >> M;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = coins[i]; j <= M; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        cout << dp[M] << "\n";
    }

    return 0;
}