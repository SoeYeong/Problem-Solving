#include <iostream>
#include <algorithm>

#define MAX 100001
using namespace std;

int N;
int arr[MAX][3];
int dp[2][MAX][3];  // max, min
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 1; i <= N; i++) {
        dp[0][i][0] = arr[i][0] + max(dp[0][i - 1][0], dp[0][i - 1][1]);
        dp[0][i][1] = arr[i][1] + max(dp[0][i - 1][0], max(dp[0][i - 1][1], dp[0][i - 1][2]));
        dp[0][i][2] = arr[i][2] + max(dp[0][i - 1][1], dp[0][i - 1][2]);

        dp[1][i][0] = arr[i][0] + min(dp[1][i - 1][0], dp[1][i - 1][1]);
        dp[1][i][1] = arr[i][1] + min(dp[1][i - 1][0], min(dp[1][i - 1][1], dp[1][i - 1][2]));
        dp[1][i][2] = arr[i][2] + min(dp[1][i - 1][1], dp[1][i - 1][2]);
    }

    cout << max(dp[0][N][0], max(dp[0][N][1], dp[0][N][2])) << ' ';
    cout << min(dp[1][N][0], min(dp[1][N][1], dp[1][N][2]));
    return 0;
}