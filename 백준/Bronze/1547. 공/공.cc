#include <iostream>
using namespace std;

int n, x, y;
int cup[4] = { 0,1,2,3 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		int temp = cup[x];
		cup[x] = cup[y];
		cup[y] = temp;
	}

	for (int i = 1; i <= 3; i++) {
		if (cup[i] == 1)
			cout << i;
	}
	return 0;
}