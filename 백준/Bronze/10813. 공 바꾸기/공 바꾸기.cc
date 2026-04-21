#include <iostream>
using namespace std;

int n, m;
int a, b;
int basket[101] = { 0, };

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		basket[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int temp = basket[a];
		basket[a] = basket[b];
		basket[b] = temp;
	}
	for (int i = 1; i <= n; i++) {
		cout << basket[i] << " ";
	}

	return 0;
}