#include <iostream>
using namespace std;

int T, N, sum;
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		sum = 0;
		int num;
		for (int j = 0; j < N; j++) {
			cin >> num;
			sum += num;
		}
		cout << sum << "\n";
	}

	return 0;
}