#include <iostream>
using namespace std;

int in, out;
int people, maxx = -1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 4; i++) {
		cin >> in >> out;
		people = people - in + out;
		if (maxx < people) maxx = people;
	}
	cout << maxx;
}