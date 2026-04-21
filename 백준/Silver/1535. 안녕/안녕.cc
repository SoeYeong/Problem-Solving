#include <iostream>
#include <algorithm>

#define NMAX 21
using namespace std;

int N;
int L[NMAX], J[NMAX];
int dp[NMAX][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> J[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < 100; j++) {
            if (L[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    cout << dp[N][99];

    return 0;
}