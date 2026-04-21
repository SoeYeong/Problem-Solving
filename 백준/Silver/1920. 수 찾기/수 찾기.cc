#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x;
int arr[100001];
int binary_search(int x) {
	int low = 0;
	int high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (x == arr[mid]) {
			return 1;
		}
		else if (x < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << binary_search(x) << "\n";
	}
	return 0;
}