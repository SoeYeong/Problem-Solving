#include <iostream>
using namespace std;

int day, car, cnt;
int ans = 91;
int main() {
	cin >> day;
	for (int i = 0; i < 5; i++) {
		cin >> car;
		if (day == car)
			cnt++;
	}
	cout << cnt;
 	return 0;
}