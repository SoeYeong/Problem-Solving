#include <iostream>
using namespace std;

int N, K;
int coin[101];
int dp[10001];
void solve() {
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = coin[i]; j <= K; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[K];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }

    solve();

    return 0;
}