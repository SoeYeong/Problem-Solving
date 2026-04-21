#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
string sqr[50];
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> sqr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; i + k < n && j + k < m; k++) {
				if (sqr[i][j] == sqr[i][j + k] && sqr[i][j] == sqr[i + k][j] && sqr[i][j] == sqr[i + k][j + k]) {
					ans = max(ans, (k + 1) * (k + 1));
				}
			}
		}
	}
	cout << ans;
}