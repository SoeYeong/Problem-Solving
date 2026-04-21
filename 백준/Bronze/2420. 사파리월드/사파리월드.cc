#include <iostream>
using namespace std;

long long n, m, ans;

int main() {
	cin >> n >> m;
	ans = n - m;
	if (ans < 0)
		ans = -ans;
	cout << ans;
	return 0;
}