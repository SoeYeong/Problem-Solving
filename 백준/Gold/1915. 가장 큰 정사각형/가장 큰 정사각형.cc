// DP
#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1001
using namespace std;

int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX];
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    string temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        for (int j = 1; j <= M; j++) {
            arr[i][j] = temp[j - 1] - '0';
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0) continue;
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans*ans;
    return 0;
}