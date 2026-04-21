#include <iostream>
using namespace std;

int n, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> k;
		while (k--) {
			cout << "=";
		}
		cout << "\n";
	}
}