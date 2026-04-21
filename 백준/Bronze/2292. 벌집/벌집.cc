#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;

	int i = 1, j = 1;
	while (j < n) {
		j += i * 6;
		i++;
	}
	cout << i;
	return 0;
}
