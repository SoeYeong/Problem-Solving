#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> T, P;
vector<int> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp.resize(N + 1, 0);
    int t, p;
    for (int i = 0; i < N; i++) {
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }

    for (int i = N - 1; i >= 0; i--) {
        if (i + T[i] - 1 < N) {
            dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
        }
        else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0];
    return 0;
}