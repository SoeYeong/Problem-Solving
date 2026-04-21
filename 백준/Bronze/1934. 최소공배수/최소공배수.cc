#include <iostream>
using namespace std;

int t, a, b;
int get_gcd(int a, int b) {
	int n = a > b ? b : a;
	int gcd = 1;
	for (int i = 1; i <= n; i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a * b / get_gcd(a, b) << "\n";
	}

	return 0;
}