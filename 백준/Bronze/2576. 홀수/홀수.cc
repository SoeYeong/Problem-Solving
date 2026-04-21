#include <iostream>
#include <algorithm>
using namespace std;

int n, sum, minn = 101;
int arr[7];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
		if (arr[i] % 2) {
			sum += arr[i];
			minn = min(minn, arr[i]);
		}
	}

	if (sum) 
		cout << sum << "\n" << minn;
	else 
		cout << -1;

	return 0;
}