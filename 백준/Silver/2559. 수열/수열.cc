#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int maxx = -10e8;
int arr[100001];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = k; i <= n; i++) {
		int temp = arr[i] - arr[i - k];
		maxx = max(maxx, temp);
	}
	cout << maxx;
	return 0;
}