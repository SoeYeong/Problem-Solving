#include <iostream>

#define MIN(X,Y) (X<Y)?X:Y
#define MAX(X,Y) (X>Y)?X:Y
using namespace std;

int C, N;
int cost[21], customer[21];
int dp[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i] >> customer[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = cost[i]; j <= 100000; j++) {
            dp[j] = MAX(dp[j], dp[j - cost[i]] + customer[i]);
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (dp[i] >= C) {
            cout << i;
            break;
        }
    }

    return 0;
}