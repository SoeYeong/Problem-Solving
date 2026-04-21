#include <iostream>
#include <algorithm>
using namespace std;

int num;
int maxx, r, c;
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> num;
			maxx = max(maxx, num);
			if (maxx == num) {
				r = i;
				c = j;
			}
		}
	}

	cout << maxx << "\n";
	cout << r << " " << c;
	return 0;
}