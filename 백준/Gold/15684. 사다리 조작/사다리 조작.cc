#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H;
int connect[11][31];
int ans = 21e8;
bool check_i2i() {
	for (int i = 1; i <= N; i++) {
		int current = i;
		for (int j = 1; j <= H; j++) {
			if (connect[current][j]) {
				current++;
			}
			else if (connect[current-1][j]) {
				current--;
			}
		}

		if (current != i) {
			return false;
		}
	}
	return true;
}
void ladder(int cnt, int idx) {
	if (cnt >= 4)
		return;

	if (check_i2i()) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (connect[j][i] || connect[j - 1][i] || connect[j + 1][i]) continue;
			connect[j][i] = 1;
			ladder(cnt + 1, i);
			connect[j][i] = 0;
		}
	}
}
void solve() {
	ladder(0, 1);
	if (ans > 3)
		cout << -1;
	else
		cout << ans;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		connect[b][a] = 1;
	}

	solve();
	return 0;
}