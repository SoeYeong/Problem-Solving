#include <iostream>
#include <map>
using namespace std;

int n, cnt;
string name1, name2;
map<string, bool> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name1 >> name2;
		if (name1 == "ChongChong")
			m.insert({ name1, true });
		else if (name2 == "ChongChong")
			m.insert({ name2, true });
		if (m[name1])
			m[name2] = true;
		if (m[name2])
			m[name1] = true;
	}
	for (auto it : m) {
		if (it.second)
			cnt++;
	}
	cout << cnt;
}