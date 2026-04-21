#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int x, y, d, g;
bool map[101][101];		// [y][x]
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int ans;
vector <pair<int, int>> dragon[20];
void calculate() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				ans++;
		}
	}
}
void turn(int idx) {
	int cnt = dragon[idx].size();

	int last_y = dragon[idx].back().first;
	int last_x = dragon[idx].back().second;

	for (int i = cnt - 2; i >= 0; i--) {
		int pre_y = dragon[idx][i].first;
		int pre_x = dragon[idx][i].second;

		int next_y = last_y - (last_x - pre_x);
		int next_x = last_x + (last_y - pre_y);
		dragon[idx].push_back({ next_y, next_x });
		map[next_y][next_x] = true;
	}
}
void solve(int idx) {
	dragon[idx].push_back({ y, x });
	map[y][x] = true;
	dragon[idx].push_back({ y + dy[d],x + dx[d] });
	map[y + dy[d]][x + dx[d]] = true;

	for (int gen = 1; gen <= g; gen++) {
		turn(idx);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		solve(i);
	}

	calculate();
	cout << ans;
	return 0;
}