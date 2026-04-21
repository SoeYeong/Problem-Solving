#include <iostream>
#include <string>
using namespace std;

string str;
int arr[26] = { 0, };
int maxx;
char ans;
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a')
			arr[str[i] - 'a']++;
		else
			arr[str[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] == maxx)
			ans = '?';
		else if (arr[i] > maxx) {
			maxx = arr[i];
			ans = 'A' + i;
		}
	}
	cout << ans;
	return 0;
}