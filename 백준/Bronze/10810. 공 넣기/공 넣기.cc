#include <iostream>
using namespace std;

int n, m;
int i, j, k;
int basket[101] = { 0, };

int main() {
	cin >> n >> m;
	for (int a = 0; a < m; a++) {
		cin >> i >> j >> k;
		for (int b = i; b <= j; b++) {
			basket[b] = k;
		}
	}

	for (int a = 1; a <= n; a++) {
		cout << basket[a] << " ";
	}

	return 0;
}