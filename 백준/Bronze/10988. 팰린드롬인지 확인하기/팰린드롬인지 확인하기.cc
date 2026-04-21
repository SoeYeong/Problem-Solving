#include <iostream>
#include <string>
using namespace std;

string str;
int ans = 1;
int main() {

	cin >> str;
	int mid = str.length() / 2;

	if (str.length() % 2) {
		for (int i = 0; i <= mid; i++) {
			if (str[i] != str[str.length() - 1 - i]) {
				ans = 0;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < mid; i++) {
			if (str[i] != str[str.length() - 1 - i]) {
				ans = 0;
				break;
			}
		}
	}

	cout << ans;
	return 0;
}