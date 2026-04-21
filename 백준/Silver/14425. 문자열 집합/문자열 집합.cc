#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, m, cnt;
map<string, bool> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		mp[temp] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (mp.find(temp) != mp.end())
			cnt++;
	}
	cout << cnt;
	return 0;
}