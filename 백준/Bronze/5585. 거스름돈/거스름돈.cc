#include <iostream>
using namespace std;

int coin[6] = { 500,100,50,10,5,1 };
int cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		cnt += n / coin[i];
		n %= coin[i];
	}
	cout << cnt;
	return 0;
}