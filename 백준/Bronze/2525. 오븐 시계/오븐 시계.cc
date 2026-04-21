#include <iostream>
using namespace std;

int h, m, mm;

int main() {
	cin >> h >> m;
	cin >> mm;

	m += mm;
	h += m / 60;

	m %= 60;
	h %= 24;
	cout << h << " " << m;

	return 0;
}