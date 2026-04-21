#include <iostream>
using namespace std;

int n, num, cnt;
bool is_prime(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > 1 && is_prime(num))
			cnt++;
	}
	cout << cnt;
	return 0;
}