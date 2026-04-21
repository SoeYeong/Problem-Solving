#include <iostream>
#include <cmath>
using namespace std;

double D, H, W, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> D >> H >> W;
	n = D / sqrt(H * H + W * W);
	H = H * n;
	W = W * n;
	cout << (int)H << " " << (int)W;

	return 0;
}