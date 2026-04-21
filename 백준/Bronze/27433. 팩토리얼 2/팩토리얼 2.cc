#include <iostream>
#include <algorithm>
using namespace std;

long long N, ans;
long long factorial(long long n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
int main() {	
	cin >> N;
	ans = factorial(N);
	cout << ans;
	return 0;
}