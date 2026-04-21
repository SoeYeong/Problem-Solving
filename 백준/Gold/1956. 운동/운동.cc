// 최단 경로 : 플로이드-워셜
#include <iostream>
#include <algorithm>

#define INF 0x7fffffff
#define MAX 401
using namespace std;

int V, E;
int road[MAX][MAX];
int ans = INF;
void init() {
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) continue;
            road[i][j] = INF;
        }
    }
}
void floyd() {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            if (road[i][k] == INF) continue;
            for (int j = 1; j <= V; j++) {
                if (road[k][j] == INF) continue;
                if (road[i][j] > road[i][k] + road[k][j]) {
                    road[i][j] = road[i][k] + road[k][j];
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;

    init();
    int from, to, cost;
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> cost;
        road[from][to] = cost;
    }

    floyd();

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) continue;
            if (road[i][j] == INF) continue;
            if (road[j][i] == INF) continue;
            ans = min(ans, road[i][j] + road[j][i]);
        }
    }

    if (ans == INF) {
        ans = -1;
    }
    cout << ans;
    return 0;
}