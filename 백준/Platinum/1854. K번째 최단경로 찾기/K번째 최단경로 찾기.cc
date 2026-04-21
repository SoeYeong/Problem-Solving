// 최단 경로 : 다익스트라
#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 0x7fffffff
using namespace std;

struct edge {
    int e, c;
};
struct cmp {
    bool operator()(int a, int b) {
        return a < b ? true : false;
    }
};
struct ecmp {
    bool operator()(edge a, edge b) {
        return a.c > b.c ? true : false;
    }
};

int N, M, K;
int a, b, c;
priority_queue<int, vector<int>, cmp> dist[MAX];
priority_queue<edge, vector<edge>, ecmp> pq;
vector<edge> adj[MAX];

void dijkstra() {
    dist[1].push(0);
    pq.push({ 1, 0 });

    edge now, next;
    while (!pq.empty()) {
        now = pq.top();
        pq.pop();
        for (int i = 0; i < adj[now.e].size(); i++) {
            next = adj[now.e][i];

            if (dist[next.e].size() < K) {
                // 저장된 경로 < K개 : 추가
                dist[next.e].push(now.c + next.c);
                pq.push({ next.e, now.c + next.c });
            }
            else if (dist[next.e].top() > now.c + next.c) {
                // 저장된 경로 == K개 && 가장 큰 값보다 작음
                dist[next.e].pop();
                dist[next.e].push(now.c + next.c);
                pq.push({ next.e, now.c + next.c });
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }
    dijkstra();
    for (int i = 1; i <= N; i++) {
        if (dist[i].size() == K) {
            cout << dist[i].top() << '\n';
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}