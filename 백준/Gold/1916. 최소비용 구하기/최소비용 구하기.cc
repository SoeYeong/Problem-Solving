#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 0x7fffffff
using namespace std;

int N, M;
int start, dest;
vector<pair<int, int>> bus[1001];
int cost[1001];
void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });
    cost[start] = 0;

    while (!pq.empty()) {
        int c = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost[cur] < c) {
            continue;
        }

        for (int i = 0; i < bus[cur].size(); i++) {
            int next = bus[cur][i].first;
            int ncost = c + bus[cur][i].second;
            if (cost[next] > ncost) {
                cost[next] = ncost;
                pq.push({ ncost, next });
            }
        }
    }
    cout << cost[dest];
}
void solve() {
    for (int i = 1; i <= N; i++) {
        cost[i] = INF;
    }
    dijkstra();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> c;
        bus[a].push_back({ b,c });
    }
    cin >> start >> dest;

    solve();

    return 0;
}