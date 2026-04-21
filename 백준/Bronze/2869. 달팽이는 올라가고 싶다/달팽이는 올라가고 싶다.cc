#include <iostream>
using namespace std;

int a, b, v;
int day;

int main() {
	cin >> a >> b >> v;

	v -= a;
	day = v / (a - b);
	v % (a - b) == 0 ? day++ : day += 2;

	cout << day;
	return 0;
}