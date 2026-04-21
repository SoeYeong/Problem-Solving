#include <iostream>
#include <cmath>
using namespace std;

int n, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	ans = pow(2, n) + 1;
	ans *= ans;
	cout << ans;
	return 0;
}