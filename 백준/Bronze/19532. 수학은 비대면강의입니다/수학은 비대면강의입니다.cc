#include <iostream>
using namespace std;

int a, b, c, d, e, f;
int x, y;

int is_ans() {
	if ((a * x + b * y == c) && (d * x + e * y == f))
		return 1;
	return 0;
}

int main() {
	cin >> a >> b >> c >> d >> e >> f;

	for (x = -999; x <= 999; x++) {
		for (y = -999; y <= 999; y++) {
			if (is_ans())
				break;
		}
		if (is_ans())
			break;
	}

	cout << x << " " << y;
	return 0;
}
