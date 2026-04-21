#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;
int cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		vector<string> v;
		for (int j = 0; j < s.length() - i; j++) {
			string temp = s.substr(j, i + 1);
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		cnt += v.size();
	}
	cout << cnt;
	return 0;
}