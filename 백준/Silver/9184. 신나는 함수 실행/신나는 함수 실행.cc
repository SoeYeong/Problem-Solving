#include <iostream>
using namespace std;

int mem[21][21][21];	// memoization
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	else if (mem[a][b][c])
		return mem[a][b][c];
	else if (a < b && b < c)
		mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return mem[a][b][c];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, ans;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		ans = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans<< "\n";
	}
	return 0;
}