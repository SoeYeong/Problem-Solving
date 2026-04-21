#include <iostream>
#include <string>
using namespace std;

int n;
string str[50];
string ans = "";
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	if (n == 1) {
		cout << str[0];
		return 0;
	}

	for (int i = 0; i < str[0].length(); i++) {
		bool check = true;
		for (int j = 1; j < n; j++) {
			if (str[j][i] != str[0][i])
				check = false;
		}
		if (check)
			ans += str[0][i];
		else ans += '?';
	}
	cout << ans;
}