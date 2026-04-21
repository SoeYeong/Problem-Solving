#include <iostream>
using namespace std;

long long a, b;

void swap() {
	long long temp = a;
	a = b;
	b = temp;
}
long long get_gcd(long long a, long long b) {
	if (a < b) swap();

	long long temp;
	while (b) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	cin >> a >> b;
	cout << a * b / get_gcd(a, b);
	return 0;
}