#include <iostream>
#include <algorithm>
using namespace std;

int n, num;
int minn = 1000001;
int maxx = -1000001;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		minn = min(minn, num);
		maxx = max(maxx, num);
	}
	cout << minn << " " << maxx;
	return 0;
}