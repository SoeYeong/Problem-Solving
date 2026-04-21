#include <iostream>
using namespace std;

struct pos {
	int x, y;
};
pos a, b, c;
void check() {
	int temp = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (temp > 0)
		cout << 1;
	else if (temp == 0)
		cout << 0;
	else
		cout << -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;

	check();

	return 0;
}