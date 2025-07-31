// DP : LCS
#include <iostream>
#include <algorithm>
#include <string>

#define MAX 1001
using namespace std;

string a, b;
int dp[MAX][MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    int N = a.length();
    int M = b.length();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[N][M] << '\n';

    return 0;
}