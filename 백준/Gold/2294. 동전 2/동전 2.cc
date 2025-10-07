#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;

int n, k;
int coin[102];
int dp[10002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    for (int i = 1; i <= k; i++) {
        dp[i] = INF;
        for (int j = 1; j <= n; j++) {
            if (i - coin[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coin[j]]+1);
            }
        }
    }
    if (dp[k] == INF) {
        cout << -1;
    }
    else {
        cout << dp[k];
    }

    return 0;
}