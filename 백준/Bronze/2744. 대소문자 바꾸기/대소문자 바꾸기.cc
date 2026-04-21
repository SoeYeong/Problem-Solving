#include <iostream>
#include <string>
using namespace std;

string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a')
			str[i] = str[i] - 'a' + 'A';
		else
			str[i] = str[i] - 'A' + 'a';
	}
	cout << str;
	return 0;
}