#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int map[9][9];
int ans = 100;
int dx[4] = { 0, -1, 0, 1 };	// right, up, left, down
int dy[4] = { 1, 0, -1, 0 };
vector <pair<int, int>> cctv_pos;

void calculate() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				cnt++;
		}
	}
	ans = min(ans, cnt);
}
void check(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		x = nx; 
		y = ny;
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
		if (map[nx][ny] == 6) return;
		if (map[nx][ny] != 0) continue;
		map[nx][ny] = '#';
	}
}
void solve(int idx) {
	int cctv_cnt = cctv_pos.size();
	if (idx == cctv_cnt) {
		calculate();
		return;
	}

	int x = cctv_pos[idx].first;
	int y = cctv_pos[idx].second;
	int backup[9][9];

	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				backup[i][j] = map[i][j];

		switch (map[x][y]) {
		case 1:
			check(x, y, dir);
			break;
		case 2:
			check(x, y, dir);
			check(x, y, dir + 2);
			break;
		case 3:
			check(x, y, dir);
			check(x, y, dir + 1);
			break;
		case 4:
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			break;
		case 5:
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
			break;
		default:
			break;
		}
		solve(idx + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = backup[i][j];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				cctv_pos.push_back({ i,j });
			}
		}
	}

	solve(0);
	cout << ans;
	return 0;
}