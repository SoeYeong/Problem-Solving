#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int arr2[500001];
int n, m;

void binary_search(int x) {
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == x) {
			cout << "1 ";
			return;
		}
		else if (arr[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << "0 ";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	
	for (int i = 0; i < m; i++) {
		binary_search(arr2[i]);
	}
	
	return 0;
}