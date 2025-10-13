#include <iostream>
#include <algorithm>
#define INF 2e9
using namespace std;

int N;
int A[1002];
int dp[1002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[i] = INF;
    }

    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (j + A[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    if (dp[N] == INF) {
        cout << -1;
    }
    else {
        cout << dp[N];
    }
    return 0;
}