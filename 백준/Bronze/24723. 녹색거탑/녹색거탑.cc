#include <iostream>
using namespace std;

int n, ans = 1;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans *= 2;
	}
	cout << ans;
	return 0;
}