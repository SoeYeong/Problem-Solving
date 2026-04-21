#include <iostream>
using namespace std;

int a1, a0, c, n0;
int ans = 0;

int main() {
	cin >> a1 >> a0 >> c >> n0;

	if (c >= a1 && a1 * n0 + a0 <= c * n0)
		ans = 1;

	cout << ans;
	return 0;
}