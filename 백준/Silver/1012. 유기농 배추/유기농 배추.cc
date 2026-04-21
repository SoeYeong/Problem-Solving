#include <iostream>
using namespace std;

int t;
int n, m, k;
int field[50][50];
int visit[50][50];
int cnt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void init() {
	cnt = 0;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			field[i][j] = 0;
		}
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visit[i][j] = 0;
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m) 
			continue;
		if (visit[xx][yy] || !field[xx][yy])
			continue;
		dfs(xx, yy);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		init();
		cin >> m >> n >> k;
		int x, y;
		while (k--) {
			cin >> x >> y;
			field[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j]) continue;
				if (!field[i][j]) continue;

				cnt++;
				dfs(i, j);
			}
		}
		cout << cnt << "\n";
	}
}