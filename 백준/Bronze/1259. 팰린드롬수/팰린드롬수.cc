#include <iostream>
#include <string>
using namespace std;

string str;
string ans = "yes";
int main() {
	while (1) {
		cin >> str;
		if (str == "0")
			break;

		int mid = str.length() / 2;

		if (str.length() % 2) {
			for (int i = 0; i <= mid; i++) {
				if (str[i] != str[str.length() - 1 - i]) {
					ans = "no";
					break;
				}
			}
		}
		else {
			for (int i = 0; i < mid; i++) {
				if (str[i] != str[str.length() - 1 - i]) {
					ans = "no";
					break;
				}
			}
		}

		cout << ans << "\n";
		ans = "yes";
	}
	
	return 0;
}