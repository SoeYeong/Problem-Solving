#include <iostream>
#include <cmath>
using namespace std;

int W, H, X, Y, P;
int cnt;
struct pos {
	int x, y;
};
pos player[50];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> W >> H >> X >> Y >> P;
	int R = H / 2;
	for (int i = 0; i < P; i++) {
		cin >> player[i].x >> player[i].y;
	}

	for (int i = 0; i < P; i++) {
		if (player[i].x >= X && player[i].y >= Y && player[i].x <= X + W && player[i].y <= Y + H)
			cnt++;
		else if (pow((player[i].x - X), 2) + pow(player[i].y - (Y + R), 2) <= R * R)
			cnt++;
		else if (pow((player[i].x - (X + W)), 2) + pow(player[i].y - (Y + R), 2) <= R * R)
			cnt++;
	}

	cout << cnt;
	return 0;
}