#include <iostream>
using namespace std;

int n, cnt;
int arr[250000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 250001; i++) {
		for (int j = 2 * i; j < 250001; j += i) {
			if (arr[j] == 0)
				arr[j] = 1;
		}
	}

	while (1) {
		cin >> n;
		if (n == 0) break;

		cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 0)
				cnt++;
		}
		cout << cnt << "\n";
	}
}