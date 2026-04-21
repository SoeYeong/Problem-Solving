#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
string answer;
int arr[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 'A']++;
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2) {
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << "I\'m Sorry Hansoo";
		return 0;
	}

	int mid = 26;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2) {
			mid = i;
			arr[i]--;
		}
		if (arr[i] % 2 == 0) {
			arr[i] /= 2;
			for (int j = 0; j < arr[i]; j++) {
				answer += i + 'A';
			}
		}
	}
	if(mid != 26)
		answer += mid + 'A';
	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++) {
			answer += i + 'A';
		}
	}

	cout << answer;
	return 0;
}