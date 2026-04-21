#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m, cnt;
string name;
map <string, bool> mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		mp[name] = false;
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (mp.find(name) != mp.end()) {
			mp[name] = true;
			cnt++;
		}
	}

	cout << cnt << "\n";
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second)
			cout << it->first << "\n";
	}
	return 0;
}