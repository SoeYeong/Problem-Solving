#include <iostream>
using namespace std;

int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++)
				cout << "* ";
			cout << '\n';
		}
		else {
			for (int j = 0; j < N; j++)
				cout << " *";
			cout << '\n';
		}
	}

	return 0;
}