#include <iostream>
using namespace std;

int n, k, cnt;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			arr[cnt] = i;
			cnt++;
		}
	}
	cout << arr[k - 1];
	return 0;
}