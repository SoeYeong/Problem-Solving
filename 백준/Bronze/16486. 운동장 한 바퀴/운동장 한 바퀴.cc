#include <iostream>
using namespace std;

const double pi = 3.141592;
double d1, d2;
double answer;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> d1 >> d2;
	answer += d1 * 2;
	answer += 2 * d2 * pi;

	cout << fixed;
	cout.precision(6);
	cout << answer;
	return 0;
}