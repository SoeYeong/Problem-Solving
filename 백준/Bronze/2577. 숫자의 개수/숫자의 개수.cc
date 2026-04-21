#include <iostream>
using namespace std;

int a, b, c;
int num[10] = { 0, };

int main() {
	cin >> a >> b >> c;
	a = a * b * c;
	while (a) {
		num[a % 10]++;
		a /= 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}