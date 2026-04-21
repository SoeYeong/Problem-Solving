#include <iostream>
using namespace std;

int t;
int a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> a >> b;
		int temp = 1;
		for (int i = 0; i < b; i++) {
			temp *= a;
			while (temp >= 10) {
				temp %= 10;
			}
		}
		if (temp == 0) cout << 10;
		else cout << temp;
		cout << "\n";
	}
}