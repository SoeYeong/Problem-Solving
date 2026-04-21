#include <iostream>
#include <cmath>
using namespace std;

int N;
long double answer;
struct pos {
	long double x, y;
};
pos point[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> point[i].x >> point[i].y;
	}

	for (int i = 1; i < N - 1; i++) {
		pos A = { point[i].x - point[0].x, point[i].y - point[0].y };
		pos B = { point[i + 1].x - point[0].x, point[i + 1].y - point[0].y };
		long double area = A.x * B.y - A.y * B.x;
		answer += area / 2;
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(answer);
	return 0;
}