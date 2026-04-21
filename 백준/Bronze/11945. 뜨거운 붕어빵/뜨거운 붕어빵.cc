#include <iostream>
#include <string>
using namespace std;

int n, m;
string arr[10];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0;
}