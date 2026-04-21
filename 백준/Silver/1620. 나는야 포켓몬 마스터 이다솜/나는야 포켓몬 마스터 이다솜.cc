#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int n, m;
map<string, int> pokemon;
vector<string> name;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		pokemon[str] = i;
		name.push_back(str);
	}
	while (m--) {
		cin >> str;
		if (str[0] >= 'A') {
			cout << pokemon[str] << "\n";
		}
		else {
			cout << name[stoi(str) - 1] << "\n";
		}
	}

	return 0;
}