#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[51][51];
int ans = 21e8;
vector <pair<int, int>> chicken;
vector <pair<int, int>> survived;
void calculate() {
	int distance = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				int minn = 100;
				for (int k = 0; k < M; k++) {
					minn = min(minn, abs(survived[k].first - i) + abs(survived[k].second - j));
				}
				distance += minn;
			}
		}
	}
	ans = min(ans, distance);
}
void solve(int cnt, int num) {
	if (cnt == M) {
		calculate();
		return;
	}
	for (int idx = num; idx < chicken.size(); idx++) {
		int x = chicken[idx].first;
		int y = chicken[idx].second;

		map[x][y] = 2;
		survived.push_back({ x,y });
		solve(cnt + 1, idx + 1);
		map[x][y] = 0;
		survived.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 2)
				chicken.push_back({ i,j });
			else
				map[i][j] = temp;
		}
	}

	solve(0, 0);
	cout << ans;
	return 0;
}