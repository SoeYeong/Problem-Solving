#include <iostream>
#include <string>
using namespace std;

string str;
int n, cnt;
bool alpha[26];
bool flag = true;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> str;

		flag = true;
		alpha[str[0] - 'a'] = true;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] == str[i - 1])
				continue;
			if (alpha[str[i] - 'a'])
			{
				flag = false;
				break;
			}
			alpha[str[i] - 'a'] = true;
		}
		if (flag) cnt++;
		for (int i = 0; i < 26; i++) {
			alpha[i] = false;
		}
	}
	cout << cnt;
	return 0;
}