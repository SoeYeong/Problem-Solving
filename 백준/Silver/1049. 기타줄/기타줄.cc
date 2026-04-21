#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a, b;
int a_min = 1001, b_min = 1001, ans = 10e8;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int q = n / 6;
	int r = n % 6;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a_min = min(a_min, a);
		b_min = min(b_min, b);
	}

	ans = min(ans, n * b_min);
	if (r == 0)
		ans = min(ans, q * a_min);
	else {
		ans = min(ans, (q + 1) * a_min);
		ans = min(ans, q * a_min + r * b_min);
	}
	cout << ans;
}