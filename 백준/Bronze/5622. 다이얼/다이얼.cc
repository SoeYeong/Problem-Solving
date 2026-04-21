#include <iostream>
#include <string>
using namespace std;

string str;
int ans;
int alphabet(char c) {
	if (c >= 'W') return 10;
	else if (c >= 'T') return 9;
	else if (c >= 'P') return 8;
	else if (c >= 'M') return 7;
	else if (c >= 'J') return 6;
	else if (c >= 'G') return 5;
	else if (c >= 'D') return 4;
	else if (c >= 'A') return 3;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		ans += alphabet(str[i]);
	}
	cout << ans;
}