#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[10];
int main() {
	cin >> n;
	while (n) {
		num[n % 10]++;
		n /= 10;
	}

	for (int i = 9; i >= 0; i--) {
		while (num[i]) {
			cout << i;
			num[i]--;
		}
	}
	return 0;
}