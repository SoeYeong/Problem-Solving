#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector <string> paint;
int visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt;
void bfs(int i, int j) {
	queue <pair<int, int>> q;
	q.push({ i, j });
	visit[i][j] = 1;
	cnt++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
			if (visit[xx][yy]) continue;
			if (paint[x][y] != paint[xx][yy]) continue;
			visit[xx][yy] = 1;
			q.push({ xx, yy });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		paint.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j]) continue;
			bfs(i, j);
		}
	}
	cout << cnt << " ";

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (paint[i][j] == 'G') {
				paint[i][j] = 'R';
			}
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j]) continue;
			bfs(i, j);
		}
	}
	cout << cnt;

	return 0;
}