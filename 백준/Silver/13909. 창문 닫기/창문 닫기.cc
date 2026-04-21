#include <iostream>
using namespace std;

int n, cnt;
int main() {
	cin >> n;
	for (int i = 1; i * i <= n; i++) {
		cnt++;
	}
	cout << cnt;
	return 0;
}