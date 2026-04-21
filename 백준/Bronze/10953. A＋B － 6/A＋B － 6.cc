#include <iostream>
using namespace std;

int t, ans;
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> str;
		ans = str[0] - '0' + str[2] - '0';
		cout << ans << "\n";
	}
}