#include <iostream>
#include <map>
using namespace std;

int N, cnt;
string name;
map<string, bool> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> name;
		if (name == "ENTER") {
			while (!m.empty()) {
				m.clear();
			}
		}
		else {
			if (!m[name]) cnt++;
			m[name] = true;
		}
	}
	cout << cnt;
}