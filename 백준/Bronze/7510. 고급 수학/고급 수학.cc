#include <iostream>
#include <algorithm>
using namespace std;

int n;
int length[3];
void print(int i) {
	cout << "Scenario #" << i + 1 << ":\n";

	if (length[2] * length[2] == length[0] * length[0] + length[1] * length[1])
		cout << "yes\n";
	else
		cout << "no\n";
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> length[0] >> length[1] >> length[2];
		sort(length, length + 3);
		print(i);
	}
	
	return 0;
}