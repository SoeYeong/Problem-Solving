#include <iostream>
using namespace std;

int n, cnt;
int arr[42];
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> n;
		arr[n % 42]++;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}