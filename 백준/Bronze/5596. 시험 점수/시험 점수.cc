#include <iostream>
using namespace std;

int n;
int sum1, sum2;
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> n;
		sum1 += n;
	}
	for (int i = 0; i < 4; i++) {
		cin >> n;
		sum2 += n;
	}
	if (sum1 >= sum2) cout << sum1;
	else cout << sum2;
 	return 0;
}