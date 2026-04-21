#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int x[100001], y[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x, x + n);
	sort(y, y + n);

	ans = (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
	cout << ans;
	return 0;
}