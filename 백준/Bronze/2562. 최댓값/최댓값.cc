#include <iostream>
#include <algorithm>
using namespace std;

int n, maxx, idx;

int main() {
	for (int i = 1; i <= 9; i++) {
		cin >> n;
		maxx = max(maxx, n);
		if (maxx == n)
			idx = i;
	}
	cout << maxx << "\n" << idx;
	return 0;
}