#include <iostream>
using namespace std;

int n, k, idx, cnt;
int coin[11];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		if (k >= coin[i]) idx = i;
	}
	while (k) {
		cnt += k / coin[idx];
		k = k % coin[idx];
		idx--;
	}
	cout << cnt;
	return 0;
}