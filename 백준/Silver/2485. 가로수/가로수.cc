#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt;
int arr[100001];
int gcd;
int GCD(int a, int b) {
	int temp;
	while (b) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	gcd = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		int temp = arr[i] - arr[i - 1];
		gcd = GCD(temp, gcd);
	}

	for (int i = 1; i < n; i++) {
		int temp = arr[i] - arr[i - 1];
		cnt += temp / gcd - 1;
	}
	cout << cnt;
	return 0;
}