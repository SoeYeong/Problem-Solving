#include <iostream>
using namespace std;

int t;
int a, b;

int main() {
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a + b << "\n";
	}
	return 0;
}