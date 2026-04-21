#include <iostream>
#include <algorithm>
using namespace std;

struct coordi {
	int x = 0, y = 0;
};
bool cmp(coordi a, coordi b) {
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

int n;
coordi _coordi[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> _coordi[i].x >> _coordi[i].y;
	}
	sort(_coordi, _coordi + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << _coordi[i].x << " " << _coordi[i].y << "\n";
	}
	return 0;
}