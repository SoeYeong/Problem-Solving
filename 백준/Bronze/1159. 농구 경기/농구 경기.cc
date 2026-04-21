#include <iostream>
using namespace std;

int N;
string name;
int cnt[26];
bool flag = false;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> name;
		cnt[name[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			flag = true;
			char c = i + 'a';
			cout << c;
		}
	}
	if (!flag)
		cout << "PREDAJA";
}