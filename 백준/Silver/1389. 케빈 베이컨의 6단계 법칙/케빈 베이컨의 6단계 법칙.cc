#include <iostream>
#include <algorithm>

#define INF 0x7ffffff
using namespace std;

int N, M;
int net[101][101];
void solve() {
    // initialize
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j || net[i][j]) continue;
            net[i][j] = INF;
        }
    }

    // floyd-warshall
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                net[i][j] = min(net[i][j], net[i][k] + net[k][j]);
            }
        }
    }

    int val = INF, ans = 0;
    for (int i = 1; i <= N; i++) {
        int temp = 0;
        for (int j = 1; j <= N; j++) {
            temp += net[i][j];
        }
        if (val > temp) {
            val = temp;
            ans = i;
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        net[a][b] = 1;
        net[b][a] = 1;
    }

    solve();

    return 0;
}