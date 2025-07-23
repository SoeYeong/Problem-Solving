// DP
#include <iostream>

#define MAX 1025
using namespace std;

int N, M;
long long arr[MAX][MAX];
long long ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }

    return 0;
}