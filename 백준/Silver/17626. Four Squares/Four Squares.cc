#include <iostream>
#include <vector>

#define INF 99999999
#define MIN(X,Y) X>Y?Y:X
using namespace std;

int n;
vector<int> dp(50001, INF);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dp[0] = 0;
    int i = 1;
    while (i * i <= 50000) {
        dp[i * i] = 1;
        i++;
    }

    for (int j = 1; j <= n; j++) {
        for (int k = 1; k*k <= j; k++) {
            dp[j] = MIN(dp[j], dp[j - k * k] + 1);
        }
    }

    cout << dp[n];
    return 0;
}