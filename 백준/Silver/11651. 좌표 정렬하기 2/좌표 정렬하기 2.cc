#include <iostream>
#include <algorithm>
using namespace std;

struct coordi {
	int x, y;
};
bool cmp(coordi a, coordi b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int n;
coordi xy[100001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xy[i].x >> xy[i].y;
	}
	sort(xy, xy + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << xy[i].x << " " << xy[i].y << "\n";
	}
	return 0;
}