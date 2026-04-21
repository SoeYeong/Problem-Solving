#include <iostream>
using namespace std;

int t;
long long n, answer;
bool isPrime(long long n) {
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (long long i = 5; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
long long findPrime(long long n) {
	while (1) {
		if (isPrime(n)) {
			break;
		}
		else {
			n++;
		}
	}
	return n;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		answer = findPrime(n);
		cout << answer << "\n";
	}

	return 0;
}