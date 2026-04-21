#include <iostream>
#include <string>
using namespace std;

int n, ans;
string num;

int main() {
	cin >> n >> num;
	for (int i = 0; i < n; i++) {
		ans += num[i] - '0';
	}
	cout << ans;
	return 0;
}