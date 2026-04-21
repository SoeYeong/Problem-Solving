#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
int arr[1001];
map <string, string> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string site, pw;
	cin >> n >> m;
	while (n--) {
		cin >> site >> pw;
		mp[site] = pw;
	}
	while (m--) {
		cin >> site;
		cout << mp[site] << "\n";
	}
	return 0;
}