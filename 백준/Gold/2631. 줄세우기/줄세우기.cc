#include <iostream>

#define MAX(X,Y) (X>Y)?X:Y
using namespace std;

int N, maxx;
int line[202];
int dp[202];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> line[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (line[j] < line[i]) {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }
        maxx = MAX(maxx, dp[i]);
    }

    cout << N - maxx;

    return 0;
}