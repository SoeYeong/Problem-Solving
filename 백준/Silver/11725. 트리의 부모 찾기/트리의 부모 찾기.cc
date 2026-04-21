#include <iostream>
#include <vector>
using namespace std;

int N;
int parent[100001];
bool visit[100001];
vector<int> v[100001];
void dfs(int n) {
    visit[n] = true;
    for (int i = 0; i < v[n].size(); i++) {
        int next = v[n][i];
        if (visit[next]) continue;
        parent[next] = n;
        dfs(next);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int a, b;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}