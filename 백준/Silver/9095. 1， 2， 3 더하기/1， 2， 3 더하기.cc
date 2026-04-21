#include <iostream>

using namespace std;

int T, n;
int num[12];
void dp() {
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;

	for (int i = 4; i < 12; i++) {
		num[i] = num[i - 3] + num[i - 2] + num[i - 1];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	dp();
	while (T--) {
		cin >> n;
		cout << num[n] << '\n';
	}

	return 0;
}