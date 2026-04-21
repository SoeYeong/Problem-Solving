#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << arr[e] - arr[s - 1] << "\n";
	}
	return 0;
}