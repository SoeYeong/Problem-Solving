#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 0x3f3f3f3f
using namespace std;

int N, ans = INF;
int house[MAX][3];
int dp[MAX][3];
void DP() {
    for (int rgb = 0; rgb < 3; rgb++) {
        for (int i = 0; i < 3; i++) {
            if (i == rgb) {
                dp[1][i] = house[1][i];
            }
            else {
                dp[1][i] = INF;
            }
        }

        for (int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
        }

        for (int i = 0; i < 3; i++) {
            if (i == rgb) continue;
            else ans = min(ans, dp[N][i]);
        }
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }
    DP();

    return 0;
}