#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[21][21];
int ans;
void findMax() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, map[i][j]);
		}
	}
}
void move(int dir) {
	// right
	if (dir == 0) {
		for (int i = 0; i < N; i++) {
			// 더하기
			for (int j = N - 1; j > 0; j--) {
				if (map[i][j] > 0) {
					int temp = j - 1;
					while (temp >= 0) {
						if (map[i][temp] == 0)
							temp--;
						else if (map[i][temp] == map[i][j]) {
							map[i][j] += map[i][temp];
							map[i][temp] = 0;
							break;
						}
						else
							break;
					}
				}

			}
			// 밀기
			for (int j = N - 1; j > 0; j--) {
				if (map[i][j] == 0) {
					int temp = j - 1;
					while (temp >= 0) {
						if (map[i][temp] == 0)
							temp--;
						else {
							map[i][j] = map[i][temp];
							map[i][temp] = 0;
							break;
						}
					}
				}
			}
		}
	}
	// up
	else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			// 더하기
			for (int j = 0; j < N - 1; j++) {
				if (map[j][i] > 0) {
					int temp = j + 1;
					while (temp < N) {
						if (map[temp][i] == 0)
							temp++;
						else if (map[temp][i] == map[j][i]) {
							map[j][i] += map[temp][i];
							map[temp][i] = 0;
							break;
						}
						else
							break;
					}
				}

			}
			// 밀기
			for (int j = 0; j < N - 1; j++) {
				if (map[j][i] == 0) {
					int temp = j + 1;
					while (temp < N) {
						if (map[temp][i] == 0)
							temp++;
						else {
							map[j][i] = map[temp][i];
							map[temp][i] = 0;
							break;
						}
					}
				}
			}
		}
	}
	// left
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			// 더하기
			for (int j = 0; j < N - 1; j++) {
				if (map[i][j] > 0) {
					int temp = j + 1;
					while (temp < N) {
						if (map[i][temp] == 0)
							temp++;
						else if (map[i][temp] == map[i][j]) {
							map[i][j] += map[i][temp];
							map[i][temp] = 0;
							break;
						}
						else
							break;
					}
				}

			}
			// 밀기
			for (int j = 0; j < N - 1; j++) {
				if (map[i][j] == 0) {
					int temp = j + 1;
					while (temp < N) {
						if (map[i][temp] == 0)
							temp++;
						else {
							map[i][j] = map[i][temp];
							map[i][temp] = 0;
							break;
						}
					}
				}
			}
		}
	}
	// down
	else {
		for (int i = 0; i < N; i++) {
			// 더하기
			for (int j = N - 1; j > 0; j--) {
				if (map[j][i] > 0) {
					int temp = j - 1;
					while (temp >= 0) {
						if (map[temp][i] == 0)
							temp--;
						else if (map[temp][i] == map[j][i]) {
							map[j][i] += map[temp][i];
							map[temp][i] = 0;
							break;
						}
						else
							break;
					}
				}

			}
			// 밀기
			for (int j = N - 1; j > 0; j--) {
				if (map[j][i] == 0) {
					int temp = j - 1;
					while (temp >= 0) {
						if (map[temp][i] == 0)
							temp--;
						else {
							map[j][i] = map[temp][i];
							map[temp][i] = 0;
							break;
						}
					}
				}
			}
		}
	}
}
void solve(int cnt) {
	if (cnt == 5) {
		findMax();
		return;
	}
	int backup[21][21];
	for (int d = 0; d < 4; d++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				backup[i][j] = map[i][j];
			}
		}
		move(d);
		solve(cnt + 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = backup[i][j];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	solve(0);
	cout << ans;
	return 0;
}