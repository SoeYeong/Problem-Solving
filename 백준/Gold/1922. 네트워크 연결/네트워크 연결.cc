#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001
using namespace std;

struct edge {
    int s, e, c;
};
bool cmp(edge &a, edge &b) {
    return a.c < b.c;
}

int N, M;
long long ans;
int parent[MAX];
vector<edge> v;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unionn(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);
    if (aRoot > bRoot) {
        parent[aRoot] = bRoot;
    }
    else {
        parent[bRoot] = aRoot;
    }
}
void init() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    sort(v.begin(), v.end(), cmp);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int s, e, c;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        v.push_back({ s,e,c });
    }

    init();
    for (int i = 0; i < M; i++) {
        if (find(v[i].s) != find(v[i].e)) {
            unionn(v[i].s, v[i].e);
            ans += v[i].c;
        }
    }
    cout << ans;

    return 0;
}