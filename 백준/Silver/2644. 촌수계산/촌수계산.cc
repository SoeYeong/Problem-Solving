#include <iostream>
#include <queue>

using namespace std;

int n, a, b, m;
int fam[51][51];
int visit[51];
void solve() {
    // bfs
    queue<int> q;
    q.push(a);
    visit[a] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (fam[now][i] == 0) continue;
            if (visit[i]) continue;
            q.push(i);
            visit[i] = visit[now] + 1;
        }
    }
}
void input() {
    cin >> n;
    cin >> a >> b;
    cin >> m;

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        fam[x][y] = 1;
        fam[y][x] = 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();
    cout << visit[b] - 1;

    return 0;
}