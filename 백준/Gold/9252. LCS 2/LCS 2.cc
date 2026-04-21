// DP : LCS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 1001
using namespace std;

string a, b;
int N, M;
int dp[MAX][MAX];
vector<char> ans;
void getRoute(int r, int c) {
    if (!r || !c) return;
    if (a[r - 1] == b[c - 1]) {
        ans.push_back(a[r - 1]);
        getRoute(r - 1, c - 1);
    }
    else {
        if (dp[r - 1][c] > dp[r][c - 1]) {
            getRoute(r - 1, c);
        }
        else {
            getRoute(r, c - 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    N = a.length();
    M = b.length();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[N][M] << '\n';

    getRoute(N, M);
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}