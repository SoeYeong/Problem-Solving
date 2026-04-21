#include <iostream>
using namespace std;

char dir[4] = { 'N', 'E', 'S', 'W' };
int t, idx;

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> t;
		if (t == 1) {
			idx++;
			if (idx == 4)
				idx = 0;
		}
		else if (t == 2) {
			idx += 2;
			if (idx > 3)
				idx -= 4;
		}
		else {
			idx--;
			if (idx < 0)
				idx = 3;
		}
	}
	cout << dir[idx];
	return 0;
}