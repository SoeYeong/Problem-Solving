#include <iostream>

#define PMAX 351
#define DMAX 100001
#define INF 999999999
#define MIN(X,Y) (X<Y)?X:Y
#define MAX(X,Y) (X>Y)?X:Y
using namespace std;

int D, P;
int L[PMAX], C[PMAX];
int dp[DMAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> P;
    for (int i = 1; i <= P; i++) {
        cin >> L[i] >> C[i];
    }

    dp[0] = INF;
    for (int i = 1; i <= P; i++) {
        for (int j = D; j >= L[i]; j--) {
            int tmp = MIN(dp[j - L[i]], C[i]);
            dp[j] = MAX(dp[j], tmp);
        }
    }

    cout << dp[D];
    return 0;
}