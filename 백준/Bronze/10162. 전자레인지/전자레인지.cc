#include <iostream>
using namespace std;

int T;
int a = 300, b = 60, c = 10;
int ans[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	
	ans[0] = T / a;
	T %= a;
	ans[1]  = T / b;
	T %= b;
	ans[2]  = T / c;
	T %= c;
	if (T)
		cout << -1;
	else
		cout << ans[0] << " " << ans[1] << " " << ans[2];

	return 0;
}