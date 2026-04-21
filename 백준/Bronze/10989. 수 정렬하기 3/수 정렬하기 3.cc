#include <iostream>
using namespace std;

int n, x;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[x]++;
	}

	for (int i = 1; i < 10001; i++) {
		while (arr[i]) {
			cout << i << "\n";
			arr[i]--;
		}
	}
	return 0;
}