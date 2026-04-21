#include <iostream>
using namespace std;

int n, m;
int n1, n2, m1, m2;
int ans;
int main() {
	cin >> n >> m;
	n--; m--;

	n1 = n / 4;
	m1 = m / 4;
	
	n2 = n % 4;
	m2 = m % 4;

	ans += (n1 > m1) ? n1 - m1 : m1 - n1;
	ans += (n2 > m2) ? n2 - m2 : m2 - n2;
	cout << ans;
	return 0;
}