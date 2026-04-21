#include <iostream>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i < N; i++)
		cout << " ";
	cout << "*\n";
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N - i; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << " ";
		cout << "*\n";
	}
}