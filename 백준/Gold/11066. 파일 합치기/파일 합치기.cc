#include <iostream>
#include <algorithm>
#define MAX 501
#define INF 0x3f3f3f3f
using namespace std;

int T, K;
int book[MAX];
int dp[MAX][MAX];
int sum[MAX];
void DP() {
    for (int i = 1; i < K; i++) {
        for (int x = 1; x <= K - i; x++) {
            int y = x + i;
            dp[x][y] = INF;

            for (int mid = x; mid < y; mid++) {
                dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x - 1]);
            }
        }
    }
    cout << dp[1][K] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> K;
        for (int i = 1; i <= K; i++) {
            cin >> book[i];
            sum[i] = sum[i - 1] + book[i];
        }
        DP();
    }
    
    return 0;
}