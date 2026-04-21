#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, H;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };
int tomato[100][100][100];
int answer;
struct pos {
	int x, y, h;
};
queue <pos> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int h = q.front().h;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int hh = h + dh[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= M || hh < 0 || hh >= H) continue;
			if (tomato[hh][xx][yy] == 0) {
				tomato[hh][xx][yy] = tomato[h][x][y] + 1;
				q.push({ xx, yy, hh });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tomato[h][i][j];
				if (tomato[h][i][j] == 1) {
					q.push({ i,j,h });
				}
			}
		}
	}

	bfs();
	
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tomato[h][i][j] == 0) {
					cout << -1;
					return 0;
				}
				else if (tomato[h][i][j] > 0) {
					answer = max(answer, tomato[h][i][j]);
				}
			}
		}
	}
	cout << answer - 1;
	return 0;
}