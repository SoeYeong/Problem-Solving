#include <iostream>
using namespace std;

int T, C;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> C;

		cout << C / 25 << " ";
		C %= 25;
		cout << C / 10 << " ";
		C %= 10;
		cout << C / 5 << " ";
		C %= 5;
		cout << C << "\n";
	}
	return 0;
}