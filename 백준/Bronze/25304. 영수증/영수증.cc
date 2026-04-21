#include <iostream>
using namespace std;

int n, x;
int a, b, sum;
int main() {
	cin >> x >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		sum += a * b;
	}
	if (sum == x)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}