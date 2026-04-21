#include <iostream>
using namespace std;

int e, s, m;
int te = 1, ts = 1, tm = 1;
int ans = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> e >> s >> m;
	while (1) {
		if (te == e && ts == s && tm == m) 
			break;
		te++;
		ts++;
		tm++;
		ans++;
		if (te > 15) te = 1;
		if (ts > 28) ts = 1;
		if (tm > 19) tm = 1;
	}
	cout << ans;
}