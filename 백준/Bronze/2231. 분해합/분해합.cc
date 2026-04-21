#include <iostream>
using namespace std;

int n, nn, sum;
int ans = 0;

int main() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		sum = 0;
		nn = i;
		sum += i;
		while (nn > 0) {
			sum += nn % 10;
			nn /= 10;
		}

		if (sum == n) {
			ans = i;
			break;
		}
	}

	cout << ans;
	return 0;
}
