#include <iostream>
using namespace std;

int n, sum;
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> n;
		sum += n * n;
	}
	cout << sum % 10;
	return 0;
}