#include <iostream>
using namespace std;

int n, cnt_2, cnt_5;
int temp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		temp = i;
		while (temp % 2 == 0) {
			cnt_2++;
			temp /= 2;
		}
		while (temp % 5 == 0) {
			cnt_5++;
			temp /= 5;
		}
	}
	int ans = (cnt_2 > cnt_5) ? cnt_5 : cnt_2;
	cout << ans;
}