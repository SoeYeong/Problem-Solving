#include <iostream>
#include <cstring>
using namespace std;

char s[101];
int arr[26] = { 0, };
int main() {
	cin >> s;
	for (int i = 0; i < strlen(s); i++) {
		arr[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}