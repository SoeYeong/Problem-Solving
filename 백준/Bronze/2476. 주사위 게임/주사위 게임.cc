#include <iostream>
using namespace std;

int N, a, b, c;
int temp, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> a >> b >> c;
		if (a == b && b == c)
			temp = 10000 + a * 1000;
		else if (a == b || a == c)
			temp = 1000 + a * 100;
		else if (b == c)
			temp = 1000 + b * 100;
		else {
			int maxx = (a > b ? (a > c ? a : c) : (b > c ? b : c));
			temp = maxx * 100;
		}
		ans = temp > ans ? temp : ans;
	}
	cout << ans;
}