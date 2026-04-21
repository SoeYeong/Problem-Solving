#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;
int a[50], b[50];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);

	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n - 1 - i];
	}
	cout << sum;
	return 0;
}