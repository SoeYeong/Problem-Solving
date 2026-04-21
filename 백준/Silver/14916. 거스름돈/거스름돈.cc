#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    for (int i = 6; i <= N; i++) {
        if (dp[i - 5] && dp[i - 2]) {
            dp[i] = min(dp[i - 5], dp[i - 2]) + 1;
        }
        else if (dp[i - 5]) {
            dp[i] = dp[i - 5] + 1;
        }
        else if (dp[i - 2]) {
            dp[i] = dp[i - 2] + 1;
        }
    }

    if (dp[N]) cout << dp[N];
    else cout << -1;

    return 0;
}