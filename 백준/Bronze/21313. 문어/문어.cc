#include <iostream>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N / 2 * 2; i++) {
		if (i % 2) {
			cout << 2;
		}
		else {
			cout << 1;
		}
		cout << " ";
	}
	if (N % 2) {
		cout << 3;
	}
	return 0;
}