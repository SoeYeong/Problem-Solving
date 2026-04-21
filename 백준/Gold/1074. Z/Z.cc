#include <iostream>
#include <cmath>
using namespace std;

int N, R, C;
long long cnt;
void zz(long long size, int r, int c) {
	if (r == R && c == C) {
		cout << cnt;
		return;
	}
	if (C < c + size && R < r + size && C >= c && R >= r) {
		zz(size / 2, r, c);
		zz(size / 2, r, c + size / 2);
		zz(size / 2, r + size / 2, c);
		zz(size / 2, r + size / 2, c + size / 2);
	}
	else {
		cnt += size * size;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R >> C;
	zz(pow(2, N), 0, 0);

	return 0;
}