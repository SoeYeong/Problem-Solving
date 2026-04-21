#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

int r;
double ans1, ans2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r;
	double pi = M_PI;
	ans1 = r * r * pi;
	ans2 = r * r * 2;

	cout << fixed << setprecision(5) << ans1 << "\n" << ans2;
}