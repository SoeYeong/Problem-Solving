#include <iostream>
using namespace std;

int a, b, c;
int ans = 91;
int main() {
	cin >> a >> b >> c;
	ans += a + b*3 + c;
	cout << "The 1-3-sum is " << ans;
 	return 0;
}