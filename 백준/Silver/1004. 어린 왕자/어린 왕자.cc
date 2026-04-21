#include <iostream>
#include <cmath>
using namespace std;

int T, n;
int cnt;
int sx, sy, ex, ey;
struct pos {
	int x, y, r;
};
pos planet[51];
void solve() {
	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (pow(planet[i].x - sx, 2) + pow(planet[i].y - sy, 2) < pow(planet[i].r, 2)) {
			if (pow(planet[i].x - ex, 2) + pow(planet[i].y - ey, 2) > pow(planet[i].r, 2))
				cnt++;
		}
		if (pow(planet[i].x - sx, 2) + pow(planet[i].y - sy, 2) > pow(planet[i].r, 2)) {
			if (pow(planet[i].x - ex, 2) + pow(planet[i].y - ey, 2) < pow(planet[i].r, 2))
				cnt++;
		}
	}
	cout << cnt << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> sx >> sy >> ex >> ey;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> planet[i].x >> planet[i].y >> planet[i].r;
		}
		solve();
	}
	
	return 0;
}