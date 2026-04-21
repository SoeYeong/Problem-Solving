#include <iostream>
#include <cmath>
using namespace std;

int t;
int x_1, y_1, r_1, x_2, y_2, r_2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> x_1 >> y_1 >> r_1;
		cin >> x_2 >> y_2 >> r_2;
		int x = pow(x_2 - x_1, 2);
		int y = pow(y_2 - y_1, 2);
		int r_dif = pow(r_2 - r_1, 2);
		int r_sum = pow(r_1 + r_2, 2);

		if (x + y + r_dif == 0)
			cout << -1;
		else if (x + y > r_sum || x + y < r_dif)
			cout << 0;
		else if (x + y == r_sum || x + y == r_dif)
			cout << 1;
		else if (x + y > r_dif && x + y < r_sum)
			cout << 2;
		cout << "\n";
	}
}