#include <iostream>
#include <cmath>
using namespace std;

long long N, R;
long long cnt;
int check(long long x, long long y) {
	if (x * x + y * y < R * R) {
		return 1;
	}
	else if (x * x + y * y > R * R) {
		return -1;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	R = N / 2;
	int xx = 1;
	for (int y = R; y > 0; y--) {
		for (int x = xx; x <= R; x++) {
			if (check(x, y) * check(x - 1, y - 1) == -1) {
				cnt++;
				xx = x;
			}
			else {
				if (x != xx) {
					break;
				}
			}
		}
	}
	cout << cnt * 4;
	return 0;
}