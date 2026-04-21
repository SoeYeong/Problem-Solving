#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector <int> graph[1001];
int visit[1001];
int cnt;
void bfs(int n) {
	queue <int> q;

	visit[n] = 1;
	q.push(n);
	cnt++;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			if (visit[graph[node][i]]) continue;
			visit[graph[node][i]] = 1;
			q.push(graph[node][i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		bfs(i);
	}
	cout << cnt;
	return 0;
}