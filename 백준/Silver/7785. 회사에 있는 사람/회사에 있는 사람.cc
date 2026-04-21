#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
string name, record;
map <string, bool, greater<string>> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;;
	for (int i = 0; i < n; i++) {
		cin >> name >> record;
		if (record == "enter")
			m[name] = true;
		else
			m.erase(name);
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << "\n";
	}
	return 0;
}