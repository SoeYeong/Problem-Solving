#include <iostream>
using namespace std;

int a, b, c;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	cin >> c;
	if (a + b >= c * 2)
		cout << a + b - c * 2;
	else
		cout << a + b;
}