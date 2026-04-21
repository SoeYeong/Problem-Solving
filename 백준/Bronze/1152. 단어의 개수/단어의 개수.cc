#include <iostream>
#include <string>
using namespace std;

string str;
int cnt;
int main() {
	getline(cin, str);

	if (str.length() == 1 && str[0] == ' ') {
		cout << cnt;
		return 0;
	}
	cnt = 1;
	for (int i = 1; i < str.length() - 1; i++) {
		if (str[i] == ' ')
			cnt++;
	}
	cout << cnt;
	return 0;
}