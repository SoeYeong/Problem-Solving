#include <iostream>
using namespace std;

int n, m;
int arr[100];
int maxx = 0;
int sum;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum > maxx && sum <= m)
					maxx = sum;
			}
		}
	}

	cout << maxx;
	return 0;
}
