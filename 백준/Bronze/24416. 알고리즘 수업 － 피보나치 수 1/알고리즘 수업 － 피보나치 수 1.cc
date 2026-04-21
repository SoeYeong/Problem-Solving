#include <iostream>
using namespace std;

int N, ans;
int fib(int n) {
	int b1 = 0;
	int b2 = 1;
	int c = n > 0 ? 1 : 0;

	for (int i = 2; i < n; i++) {
		b1 = b2;
		b2 = c;
		c = b1 + b2;
	}
	return c;
}
int main() {	
	cin >> N;
	ans = fib(N);
	cout << ans << " " << N - 2;
	return 0;
}