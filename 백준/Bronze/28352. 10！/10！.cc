#include <iostream>
using namespace std;

int n;
int ans = 6;
int main() {
	cin >> n;
	for (int i = n; i > 10; i--) {
		ans *= i;
	}
	cout << ans;
	return 0;
}