#include <iostream>
using namespace std;

int n, i = 1;
bool flag = 1;
int main() {
	cin >> n;
	while (i) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		for (int j = 0; j < 2 * (n - i); j++) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";

		if (i == n)
			flag = 0;

		flag ? i++ : i--;
	}
	return 0;
}