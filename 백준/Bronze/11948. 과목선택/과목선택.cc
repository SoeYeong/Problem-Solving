#include <iostream>
#include <algorithm>
using namespace std;

int abcd[4];
int e, f;
int sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> abcd[0] >> abcd[1] >> abcd[2] >> abcd[3];
	cin >> e >> f;
	sort(abcd, abcd + 4);
	sum += abcd[3] + abcd[2] + abcd[1];
	sum += (e > f) ? e : f;
	cout << sum;
}