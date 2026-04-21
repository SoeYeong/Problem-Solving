#include <iostream>
#include <vector>
using namespace std;

int N;
void isPerfet() {
	vector <int> v;
	for (int i = 1; i <= N / 2; i++) {
		if (N % i == 0) {
			v.push_back(i);
		}
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	if (sum == N) {
		cout << N << " = " << v[0];
		for (int i = 1; i < v.size(); i++) {
			cout << " + " << v[i];
		}
		cout << '\n';
	}
	else {
		cout << N << " is NOT perfect.\n";
	}
}
int main() {
	while (1) {
		cin >> N;
		if (N == -1) {
			break;
		}
		isPerfet();
	}

	return 0;
}