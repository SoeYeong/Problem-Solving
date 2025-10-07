#include <iostream>
#include <algorithm>
#define MAX 502
using namespace std;

int N, ans;
int arr[MAX];
int dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        cin >> arr[n];
    }

    for (int i = 1; i < MAX; i++) {
        if (arr[i] == 0) continue;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << N - ans;
    return 0;
}