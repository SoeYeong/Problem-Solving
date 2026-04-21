#include <iostream>
using namespace std;

int x, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x;
	for (int i = 64; i >= 1; i /= 2) {
		ans += x / i;
		x %= i;
	}
	cout << ans;
}