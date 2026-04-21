#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m, x;
map <int, int> mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (mp.find(x) == mp.end())
			mp.insert({ x, 1 });
		else
			mp[x]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (mp.find(x) == mp.end())
			cout << "0 ";
		else
			cout << mp[x] << " ";
	}

	return 0;
}