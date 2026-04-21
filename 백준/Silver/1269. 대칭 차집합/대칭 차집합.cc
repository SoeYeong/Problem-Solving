#include <iostream>
#include <map>
using namespace std;

int a, b, num;
map <int, bool> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;;
	for (int i = 0; i < a + b; i++) {
		cin >> num;
		if (m[num])
			m.erase(num);
		else
			m[num] = true;
	}
	cout << m.size();
	return 0;
}