#include <iostream>
using namespace std;

long long n, ans;

int main() {
	cin >> n;

	ans = n * (n - 1) * (n - 2) / 6;
	cout << ans << "\n3";
	return 0;
}