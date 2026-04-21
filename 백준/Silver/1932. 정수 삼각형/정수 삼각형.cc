// DP
#include <iostream>
#include <algorithm>

#define MAX 501
using namespace std;

int N;
int tri[MAX][MAX];
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
            tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        ans = max(ans, tri[N][i]);
    }
    cout << ans;
    return 0;
}