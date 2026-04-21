#include <iostream>
using namespace std;

int N, M;
int flag, minn, sum;
bool isPrime(int n) {
	if (n == 1) return false;
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			if (!flag)
				minn = i;
			sum += i;
			flag = 1;
		}
	}
	if (sum) {
		cout << sum << "\n" << minn;
	}
	else cout << -1;
}