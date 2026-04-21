#include <iostream>
using namespace std;

int N, M, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		if (N % M == 0)
			cout << "multiple\n";
		else if (M % N == 0)
			cout << "factor\n";
		else
			cout << "neither\n";
	}
}