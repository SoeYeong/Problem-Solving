// 다익스트라
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x7fffffff
#define MAX 20001
using namespace std;

struct edge {
    int e, c;
};
struct compare {
    bool operator()(edge &a, edge &b) {
        if (a.c != b.c) return a.c > b.c;
        return a.e > b.e;
    }
};

int V, E, K;
int u, v, w;
int dist[MAX];
priority_queue<edge, vector<edge>, compare> pq;
vector<edge> adj[MAX];

void init() {
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dist[K] = 0;
}
void dijkstra() {
    pq.push({ K,0 });
    edge now, next;
    while (!pq.empty()) {
        now = pq.top();
        pq.pop();

        if (dist[now.e] < now.c) continue;

        for (int i = 0; i < adj[now.e].size(); i++) {
            next = adj[now.e][i];

            if (dist[next.e] > now.c + next.c) {
                dist[next.e] = now.c + next.c;
                pq.push({ next.e, dist[next.e] });
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    init();
    dijkstra();

    for (int i = 1; i <= V; i++) {
        if (K == i) {
            cout << "0\n";
        }
        else if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}