#include <iostream>
using namespace std;

int arr[101][101];
int N, M, ans;
int lx, ly, rx, ry;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	while (N--) {
		cin >> lx >> ly >> rx >> ry;
		for (int i = lx; i <= rx; i++) {
			for (int j = ly; j <= ry; j++) {
				arr[i][j]++;
			}
		}
	}
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (arr[i][j] > M)
				ans++;
		}
	}
	cout << ans;
}