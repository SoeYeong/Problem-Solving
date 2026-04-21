#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string word[20001];
int cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	sort(word, word + n, cmp);

	cout << word[0] << "\n";
	for (int i = 1; i < n; i++) {
		if (word[i] == word[i - 1])
			continue;
		cout << word[i] << "\n";
	}
	return 0;
}