#include <iostream>
#include <algorithm>
#define INF 0xffff
using namespace std;

int n, m;
int dist[201][201];
int map[201][201];
void solve() {
    //init
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = j;
            if (i == j || dist[i][j]) continue;
            dist[i][j] = INF;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if (i != k) map[i][j] = map[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "- ";
            }
            else {
                cout << map[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
void input() {
    cin >> n >> m;

    int s, e, d;
    while (m--) {
        cin >> s >> e >> d;
        dist[s][e] = d;
        dist[e][s] = d;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    return 0;
}