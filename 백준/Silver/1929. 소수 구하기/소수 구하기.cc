#include <iostream>
using namespace std;

int m, n;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		for (int j = 2 * i; j < n + 1; j += i) {
			if (arr[j] == 0)
				arr[j] = 1;
		}
	}

	for (int i = m; i <= n; i++) {
		if (arr[i] == 0)
			cout << i << "\n";
	}
}