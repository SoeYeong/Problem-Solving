// DP
#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 1001
#define INF 0x7fffffff
using namespace std;

int T, N;
int sum[MAX];
int card[MAX];
// i ~ j번 카드가 있을 때 얻을 수 있는 최대 점수
int dp[MAX][MAX];

void init() {
    memset(sum, 0, sizeof(sum));
    memset(card, 0, sizeof(card));
    memset(dp, 0, sizeof(dp));
}
int mem(int left, int right) {
    if (left == right) return card[left];
    if (dp[left][right] != 0) return dp[left][right];

    int s = sum[right] - sum[left - 1];
    return dp[left][right] = max(s - mem(left + 1, right), s - mem(left, right - 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;

        init();
        for (int j = 1; j <= N; j++) {
            cin >> card[j];
            sum[j] = sum[j - 1] + card[j];
        }
        cout << mem(1, N) << '\n';
    }

    return 0;
}