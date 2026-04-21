#include <iostream>
#include <string>
using namespace std;

string gear[5];
int isRotate[5];	// 회전할 방향 저장
int K, num, dir;
int score;
void init() {
	for (int i = 1; i < 5; i++)
		isRotate[i] = 0;
}
void calculate() {
	if (gear[1][0] == '1')	score += 1;
	if (gear[2][0] == '1')	score += 2;
	if (gear[3][0] == '1')	score += 4;
	if (gear[4][0] == '1')	score += 8;
}
void turn(int idx, int d) {
	if (d == -1)
		gear[idx] = gear[idx].substr(1, 7) + gear[idx][0];
	else if (d == 1)
		gear[idx] = gear[idx][7] + gear[idx].substr(0, 7);
}
void left_check(int idx, int d) {
	if (idx <= 1)
		return;
	if (gear[idx][6] != gear[idx - 1][2]) {
		isRotate[idx - 1] = d * -1;
		left_check(idx - 1, d * -1);
	}
}
void right_check(int idx, int d) {
	if (idx >= 4) return;
	if (gear[idx][2] != gear[idx + 1][6]) {
		isRotate[idx + 1] = d * -1;
		right_check(idx + 1, d * -1);
	}
}
void check(int idx, int d) {
	isRotate[idx] = d;
	left_check(idx, d);
	right_check(idx, d);

	for (int i = 1; i < 5; i++) {
		turn(i, isRotate[i]);
	}
}
int main() {
	for (int i = 1; i < 5; i++)
		cin >> gear[i];

	cin >> K;
	for (int i = 0; i < K; i++){
		cin >> num >> dir;
		init();
		check(num, dir);
	}
	calculate();
	cout << score;
	return 0;
}