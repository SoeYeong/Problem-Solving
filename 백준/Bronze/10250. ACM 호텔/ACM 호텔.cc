#include <iostream>
using namespace std;

int t, h, w, n;
int f, num;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		f = (n - 1) % h + 1;
		num = (n - 1) / h + 1;
		cout << f * 100 + num << "\n";;
	}
	return 0;
}