#include <iostream>
#include <algorithm>
using namespace std;

int n, m, v;
int arr[201];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		arr[m + 100]++;
	}
	cin >> v;
	cout << arr[v + 100];
	return 0;
}