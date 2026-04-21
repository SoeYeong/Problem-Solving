// LCA
// 1. BFS/DFS -> parent 배열 완성
// 2. depth 차이 구하기
// 3. depth 동일하게 맞추기
// 4. 최소 공통 조상 찾기
#include <iostream>
#include <vector>
#include <queue>

#define KMAX 17
#define MAX 100001
using namespace std;

int N, M, K;
vector<int> adj[MAX];
queue<int> q;
int depth[MAX], parent[KMAX + 1][MAX];

int lca(int a, int b) {
    // depth 차이 구하기
    if (depth[a] < depth[b]) {
        a ^= b; b ^= a; a ^= b;
    }
    int diff = depth[a] - depth[b];

    // depth 맞추기
    for (int k = K; k >= 0; k--) {
        if (diff >= (1 << k)) {
            a = parent[k][a];
            diff = depth[a] - depth[b];
        }
    }

    // a == b 이면 return
    if (a == b) {
        return a;
    }

    // a != b 이면 올라가면서 lca 찾기
    for (int k = K; k >= 0; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    return parent[0][a];
}
void setting() {
    // K 구하기
    int n = N - 1;
    while (n > 0) {
        n >>= 1;
        K++;
    }

    // depth 배열
    q.push(1);
    depth[1] = 1;
    int now;

    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (depth[next]) continue;
            depth[next] = depth[now] + 1;
            parent[0][next] = now;
            q.push(next);
        }
    }

    // parent 배열
    for (int k = 1; k <= K; k++) {
        for (int v = 1; v <= N; v++) {
            parent[k][v] = parent[k - 1][parent[k - 1][v]];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    setting();

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}