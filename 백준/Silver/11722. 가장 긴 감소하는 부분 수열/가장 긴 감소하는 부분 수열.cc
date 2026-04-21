#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int arr[1001];
int dp[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        dp[i] = 1;
        for (int j = N - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}