#include <iostream>
using namespace std;

int n, m;
int gcd, lcm;
int main() {
	cin >> n >> m;
	int temp = (n > m) ? m : n;
	for (int i = 1; i <= temp; i++) {
		if (n % i == 0 && m % i == 0)
			gcd = i;
	}
	lcm = n * m / gcd;
	cout << gcd << "\n" << lcm;
	return 0;
}