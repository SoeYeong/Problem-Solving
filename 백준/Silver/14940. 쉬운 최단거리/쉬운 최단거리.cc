#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
int visit[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sr, sc;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ sr, sc });

	int nowr, nowc;
	while (!q.empty()) {
		nowr = q.front().first;
		nowc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextr = nowr + dx[i];
			int nextc = nowc + dy[i];

			if (nextr < 0 || nextr >= n || nextc < 0 || nextc >= m) continue;
			if (map[nextr][nextc] == 0) continue;
			if (visit[nextr][nextc]) continue;
			visit[nextr][nextc] = visit[nowr][nowc] + 1;
			q.push({ nextr, nextc });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				sr = i, sc = j;
				map[i][j] = 0;
			}
		}
	}

	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && (visit[i][j] == 0)) {
				cout << -1 << ' ';
			}
			else {
				cout << visit[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}