#include <iostream>
using namespace std;

int a, b;
int arr[1001];
int sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	int idx = 1;
	for (int i = 1; idx < 1001; i++) {
		int temp = i;
		while (temp--) {
			arr[idx] = i;
			idx++;
            if (idx > 1000) break;
		}
	}

	for (int i = a; i <= b; i++)
		sum += arr[i];
	cout << sum;
}