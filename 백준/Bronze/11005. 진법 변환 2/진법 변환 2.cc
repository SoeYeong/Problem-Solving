#include <iostream>
#include <cstring>
using namespace std;

int n, b;
char ans[100];
int main() {
	cin >> n >> b;
	int j = 0;
	while (n) {
		int temp = n % b;
		if (temp >= 10)
			ans[j] = 'A' + temp - 10;
		else
			ans[j] = '0' + temp;
		j++;
		n /= b;
	}

	for (int i = strlen(ans) - 1; i >= 0; i--)
		cout << ans[i];
	return 0;
}