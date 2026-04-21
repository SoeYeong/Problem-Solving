#include <iostream>
#include <vector>

#define MAX(X,Y) X>Y?X:Y
using namespace std;

int n;
int box[1002];
int dp[1002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> box[i];
    }

    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (box[i] > box[j]) {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }
        maxx = MAX(dp[i], maxx);
    }

    cout << maxx;
    return 0;
}