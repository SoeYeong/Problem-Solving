#include <iostream>
using namespace std;

int n;
int sum = 1;
int main() {
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		while(n) {
			if (n % 10 == 0) {
				sum += 4;
			}
			else if (n % 10 == 1) {
				sum += 2;
			}
			else {
				sum += 3;
			}
			sum++;
			n /= 10;
		}
		cout << sum << "\n";
		sum = 1;
	}

	return 0;
}