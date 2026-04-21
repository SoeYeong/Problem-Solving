#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> v[1001];
vector<int> visit(1001);
void dfs(int n) {
	cout << n << " ";
	for (int i = 0; i < v[n].size(); i++) {
		if (visit[v[n][i]]) continue;
		visit[v[n][i]] = 1;
		dfs(v[n][i]);
	}
}
void bfs() {
	vector<int> visit2(1001);
	queue<int> q;
	visit2[V] = 1;
	q.push(V);

	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			if (visit2[v[node][i]]) continue;
			visit2[v[node][i]] = 1;
			q.push(v[node][i]);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	visit[V] = 1;
	dfs(V);
	cout << '\n';
	bfs();

	return 0;
}