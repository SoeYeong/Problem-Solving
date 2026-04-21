#include <iostream>
#include <string>
using namespace std;

string str;
int cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	for (int i = 1; i < str.length(); i++) {
		if (str[i - 1] != str[i])
			cnt++;
	}
	cout << (cnt + 1) / 2;
}