// 단절점
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001
using namespace std;

int V, E, a, b, cnt = 1;
int visit[MAX];
//int lows[MAX];
bool isCut[MAX];    // 단절점 저장
vector<int> adj[MAX];
int dfs(int now, bool isRoot) {
    visit[now] = cnt++;
    int low = visit[now];

    int child = 0;
    int next;
    for (int i = 0; i < adj[now].size(); i++) {
        next = adj[now][i];
        if (visit[next]) {
            low = min(low, visit[next]);
            continue;
        }
        child++;
        int lowChild = dfs(next, false);
        if (!isRoot && visit[now] <= lowChild) {
            isCut[now] = true;
        }
        low = min(low, lowChild);
    }

    if (isRoot && child > 1) {
        isCut[now] = true;
    }
    return low;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) {
        if (visit[i]) continue;
        dfs(i, true);
    }

    int ans = 0;
    for (int i = 1; i <= V; i++) {
        if (isCut[i]) ans++;
    }
    cout << ans << '\n';

    for (int i = 1; i <= V; i++) {
        if (isCut[i]) cout << i << ' ';
    }

    return 0;
}