// DP : 사선 DP
#include <iostream>
#include <algorithm>

#define MAX 201
#define INF 0x7fffffff
using namespace std;

int N, K;
int arr[MAX];
int dp[MAX][MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            int s = j;
            int e = j + i;
            int temp = INF;
            for (int k = s; k < e; k++) {
                temp = min(temp, dp[s][k] + dp[k + 1][e] + (arr[s] != arr[e]));
            }
            dp[s][e] = temp;
        }
    }

    cout << dp[1][N];
    return 0;
}