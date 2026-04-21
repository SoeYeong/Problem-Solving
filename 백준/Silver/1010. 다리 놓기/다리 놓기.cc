#include <iostream>
using namespace std;

long long t, n, k;
long long ans;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		ans = 1;
		for (int i = 1; i <= k; i++) {
			ans *= n;
			n--;
			ans /= i;
		}
		cout << ans << "\n";
	}
	return 0;
}