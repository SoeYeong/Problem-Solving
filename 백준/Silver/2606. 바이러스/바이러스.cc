#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int cnt;
vector<int> connect[101];
vector<int> visit(101);
queue <int> q;
void bfs() {
	q.push(1);
	visit[1] = 1;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < connect[node].size(); i++) {
			if (visit[connect[node][i]]) continue;
			q.push(connect[node][i]);
			visit[connect[node][i]] = 1;
			cnt++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		connect[v1].push_back(v2);
		connect[v2].push_back(v1);
	}
	bfs();
	cout << cnt;
	return 0;
}