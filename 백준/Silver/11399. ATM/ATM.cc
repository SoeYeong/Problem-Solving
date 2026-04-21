#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;
int arr[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		sum += arr[i] * (n - i);
	}
	cout << sum;
	return 0;
}