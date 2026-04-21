#include <iostream>
#include <string>
using namespace std;

long long n, sum;
int main() {
	cin >> n;
	sum = n * (n - 1) * (n + 1) / 2;
	cout << sum;
	return 0;
}