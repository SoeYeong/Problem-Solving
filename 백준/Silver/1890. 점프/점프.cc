#include <iostream>
using namespace std;

int N;
int map[101][101];
long long dp[101][101];
void solve() {
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;
            int down = i + map[i][j];
            int right = j + map[i][j];
            if (down < N) {
                dp[down][j] += dp[i][j];
            }
            if (right < N) {
                dp[i][right] += dp[i][j];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    solve();
    cout << dp[N - 1][N - 1];
    return 0;
}