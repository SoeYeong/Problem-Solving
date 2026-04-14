#include <iostream>
using namespace std;

int n;
int cnt = 0, ans = 665;

int main() {
	cin >> n;

	while (cnt != n) {
		ans++;
		int temp = ans;
		while (temp) {
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		}
	}

	cout << ans;
	return 0;
}