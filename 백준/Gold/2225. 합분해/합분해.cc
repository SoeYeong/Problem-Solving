#include <iostream>

#define MAX 201
#define MOD 1000000000
using namespace std;

int N, K;
int dp[MAX][MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= K; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[N][K];
    
    return 0;
}