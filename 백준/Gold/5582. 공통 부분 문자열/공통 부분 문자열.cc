// DP
#include <iostream>
#include <algorithm>
#include <string>
#define MAX 4001
using namespace std;

string a, b;
int dp[MAX][MAX];
int len;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                len = max(len, dp[i][j]);
            }
        }
    }

    cout << len;
    return 0;
}