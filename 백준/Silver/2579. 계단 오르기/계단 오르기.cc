#include <iostream>
#include <algorithm>

#define MAX 301
using namespace std;

int N;
int stair[MAX];
int dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stair[i];
    }

    dp[1] = stair[1];
    dp[2] = stair[2] + stair[1];
    dp[3] = max(stair[3] + stair[1], stair[3] + stair[2]);
    for (int i = 4; i <= N; i++) {
        dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
    }

    cout << dp[N];
    return 0;
}