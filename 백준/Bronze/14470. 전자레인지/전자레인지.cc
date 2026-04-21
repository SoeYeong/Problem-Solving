#include <iostream>
using namespace std;

int a, b, c, d, e;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c >> d >> e;

	if (a < 0) {
		ans += c * (-a);
		a = 0;
	}
	if (a == 0) ans += d;
	ans += (b - a) * e;
	cout << ans;
}