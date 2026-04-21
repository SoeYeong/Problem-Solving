#include <iostream>
#include <algorithm>
#include <cstring>

#define NMAX 1001
#define TMAX 1001
using namespace std;

int N, T;
int d[NMAX], m[NMAX];
int dp[NMAX][TMAX];
int sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        cin >> d[i] >> m[i];
        sum += m[i];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = sum;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            if (d[i] <= j) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - d[i]] - m[i]);
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }

    cout << dp[N][T];
    return 0;
}