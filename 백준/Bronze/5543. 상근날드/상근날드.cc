#include <iostream>
using namespace std;

int b, d;
int bmin = 2001, dmin = 2001;
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> b;
		bmin = (bmin > b) ? b : bmin;
	}
	for (int i = 0; i < 2; i++) {
		cin >> d;
		dmin = (dmin > d) ? d : dmin;
	}
	cout << bmin + dmin - 50;
	return 0;
}