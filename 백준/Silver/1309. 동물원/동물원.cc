#include <iostream>
using namespace std;

int N;
int dp[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    }

    cout << dp[N];
    return 0;
}