#include <iostream>
using namespace std;

int L, A, B, C, D;
int r1, r2;
int main() {
	cin >> L >> A >> B >> C >> D;
	r1 = A / C;
	r2 = B / D;

	if (A % C != 0)
		r1++;
	if (B % D != 0)
		r2++;
	r1 = (r1 > r2) ? r1 : r2;
	cout << L - r1;
	return 0;
}