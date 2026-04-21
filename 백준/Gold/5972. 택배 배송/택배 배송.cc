#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0xfffffff
using namespace std;

int N, M;
vector<int> dist(50001, INF);
vector<pair<int, int>> v[50001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void solve() {
    dist[1] = 0;
    pq.push({ 1,0 });
    while (!pq.empty()) {
        int now = pq.top().first;
        int dis = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int ndis = v[now][i].second;
            if (dist[next] > dist[now] + ndis) {
                dist[next] = dist[now] + ndis;
                pq.push({ next,ndis });
            }
        }
    }
}
void input() {
    cin >> N >> M;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();
    cout << dist[N];

    return 0;
}