#include <iostream>
using namespace std;

int k, n, m;
int ans;
int main() {
	cin >> k >> n >> m;
	ans = (k * n <= m) ? 0 : k * n - m;
	cout << ans;
	return 0;
}