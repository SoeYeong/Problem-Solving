#include <iostream>
using namespace std;

long long n;
long long ans;

int main() {
	cin >> n;
	ans = n * (n - 1) / 2;
	cout << ans << "\n2";
	return 0;
}