#include <iostream>
#include <string>
using namespace std;

string str;
int L;
long long M = 1234567891;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> str;
	long long r = 1;
	long long ans = 0;

	for (int i = 0; i < L; i++) {
		ans = (ans + (str[i] - 96) * r) % M;
		r = (r * 31) % M;
	}
	cout << ans;
}