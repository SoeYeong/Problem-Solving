#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    for (int i = 4; i <= N; i++) {
        dp[i] = min(dp[i - 3] + 1, dp[i - 1] + 1);
    }

    if (dp[N] % 2) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }
    return 0;
}