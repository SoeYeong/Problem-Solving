#include <iostream>
using namespace std;
int T;
int a, b;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << "\n";
	}

	return 0;
}