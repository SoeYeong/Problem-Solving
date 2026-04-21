#include <iostream>
using namespace std;

int n, m;
int i, j;
int basket[101];
int temp[101];
int main() {
	cin >> n >> m;
	for (int k = 1; k <= n; k++) {
		basket[k] = k;
	}

	for (int k = 0; k < m; k++) {
		cin >> i >> j;
		int x = i;
		for (int l = j; l >= i; l--) {
			temp[x] = basket[l];
			x++;
		}
		for (int l = i; l <= j; l++)
			basket[l] = temp[l];
	}

	for (int k = 1; k <= n; k++) {
		cout << basket[k] << " ";
	}
	return 0;
}