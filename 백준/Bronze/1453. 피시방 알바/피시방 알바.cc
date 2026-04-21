#include <iostream>
using namespace std;

int n, cnt;
int guest[100], pc[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> guest[i];
	}
	for (int i = 0; i < n; i++) {
		if (!pc[guest[i]]) {
			pc[guest[i]] = 1;
		}
		else
			cnt++;
	}
	cout << cnt;
	return 0;
}