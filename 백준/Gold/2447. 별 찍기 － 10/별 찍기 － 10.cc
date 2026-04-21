#include <iostream>
using namespace std;

int N;
void print_star(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << " ";
	else {
		if (n / 3 == 0)
			cout << "*";
		else
			print_star(i, j, n / 3);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			print_star(i, j, N);
		}
		cout << "\n";
	}
}