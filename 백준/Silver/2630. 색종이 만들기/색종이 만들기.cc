#include <iostream>
using namespace std;

int N;
int arr[129][129];
int white, blue;
void recur(int x, int y, int k) {
	bool cut = false;
	int first_color = arr[x][y];
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (arr[i][j] != first_color) {
				cut = true;
				break;
			}
		}
	}

	if (cut) {
		recur(x, y, k / 2);
		recur(x, y + k / 2, k / 2);
		recur(x + k / 2, y, k / 2);
		recur(x + k / 2, y + k / 2, k / 2);
	}
	else {
		if (first_color == 1) {
			blue++;
		}
		else {
			white++;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	recur(0, 0, N);
	cout << white << '\n';
	cout << blue;

	return 0;
}