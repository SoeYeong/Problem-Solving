// DP : sliding window 이용
#include <iostream>

#define MAX 10002
#define MOD 1000000007
using namespace std;

int N;
int arr[MAX];
long long dp[2][MAX]; 
// dp[0] : 이전 제단의 경우의 수, dp[1] : 현재 제단의 경우의 수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // 초기값
    if (arr[1] == -1 || arr[1] == 0) {
        dp[0][0] = 1;
    }
    else {
        dp[0][0] = 0;
    }

    // 점화식
    for (int i = 2; i <= N; i++) {
        fill_n(&dp[1][0], MAX, 0);
        if (arr[i] == -1) {
            dp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
            for (int j = 1; j <= MAX / 2; j++) {
                dp[1][j] = (dp[0][j - 1] + dp[0][j] + dp[0][j + 1]) % MOD;
            }
        }
        else if (arr[i] == 0) { 
            dp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
        }
        else {
            dp[1][arr[i]] = (dp[0][arr[i] - 1] + dp[0][arr[i]] + dp[0][arr[i] + 1]) % MOD;
        }

        swap(dp[0], dp[1]);
    }

    cout << dp[0][0];

    return 0;
}