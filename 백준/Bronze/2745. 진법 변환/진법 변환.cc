#include <iostream>
#include <string>
using namespace std;

string str;
int n, ans;
int nn = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str >> n;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] >= 'A')
			ans += (str[i] - 'A' + 10) * nn;
		else
			ans += (str[i] - '0') * nn;
		nn *= n;
	}
	cout << ans;
	return 0;
}