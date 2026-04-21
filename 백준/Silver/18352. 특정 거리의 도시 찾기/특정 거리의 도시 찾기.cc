#include <iostream>
#include <vector>
#include <queue>

#define MAX 0xfffffff
using namespace std;

int N, M, K, X;
int dist[300001];
vector<int> city[300001];
vector<int> v;

void init() {
    for (int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }
}
void dijkstra() {
    init();
    dist[X] = 0;

    queue<pair<int, int>> pq;
    pq.push({ X, 0 });

    while (!pq.empty()) {
        pair<int, int> now = pq.front();
        pq.pop();

        for (int i = 0; i < city[now.first].size(); i++) {
            int next = city[now.first][i];
            if (dist[next] > dist[now.first] + 1) {
                dist[next] = dist[now.first] + 1;
                pq.push({ next, 1 });
            }
        }
    }
}
void findK() {
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            v.push_back(i);
        }
    }

    if (v.size() == 0) {
        cout << -1;
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
}
void solution() {
    dijkstra();
    findK();
}
void input() {
    cin >> N >> M >> K >> X;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        city[a].push_back(b);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solution();

    return 0;
}