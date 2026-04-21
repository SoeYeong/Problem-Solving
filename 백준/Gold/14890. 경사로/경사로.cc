#include <iostream>
#include <queue>
using namespace std;

#define MAX 101

int N, L;
int cnt;
int map[MAX][MAX];

void check_row() {
	for (int i = 0; i < N; i++) {
		// 1. 높이 모두 같은지 확인
		bool sameFlag = true;
		for (int j = 1; j < N; j++) {
			if (map[i][j] != map[i][j - 1]) {
				sameFlag = false;
				break;
			}
		}
		if (sameFlag) {
			cnt++;
			continue;
		}

		// 2. 경사로 놓을 수 있는지 확인
		queue <pair<int, int>> q;
		int same_cnt = 1;
		for (int j = 1; j < N; j++) {
			if (map[i][j] == map[i][j - 1]) {
				same_cnt++;
			}
			else {
				q.push({ same_cnt, map[i][j] - map[i][j - 1] });
				same_cnt = 1;
			}

			if (j == N - 1) {
				q.push({ same_cnt, 0 });
			}
		}

		bool valid = true;
		while (!q.empty()) {
			int length = q.front().first;
			int height = q.front().second;
			q.pop();
			
			if (height > 1 || height < -1) {
				valid = false;
			}
			else if (height == 1 && length < L) {
				valid = false;
			}
			else if (height == -1 && (q.front().second == 1) && (q.front().first < 2 * L)) {
				valid = false;
			}
			else if (height == -1 && (q.front().first < L)) {
				valid = false;
			}
			if (!valid)
				break;
		}
		if (valid)
			cnt++;
	}
}
void check_col() {
	for (int i = 0; i < N; i++) {
		// 1. 높이 모두 같은지 확인
		bool sameFlag = true;
		for (int j = 1; j < N; j++) {
			if (map[j][i] != map[j - 1][i]) {
				sameFlag = false;
				break;
			}
		}
		if (sameFlag) {
			cnt++;
			continue;
		}

		// 2. 경사로 놓을 수 있는지 확인
		queue <pair<int, int>> q;
		int same_cnt = 1;
		for (int j = 1; j < N; j++) {
			if (map[j][i] == map[j - 1][i]) {
				same_cnt++;
			}
			else {
				q.push({ same_cnt, map[j][i] - map[j - 1][i] });
				same_cnt = 1;
			}

			if (j == N - 1) {
				q.push({ same_cnt, 0 });
			}
		}
		bool valid = true;
		while (!q.empty()) {
			int length = q.front().first;
			int height = q.front().second;
			q.pop();

			if (height > 1 || height < -1) {
				valid = false;
			}
			else if (height == 1 && length < L) {
				valid = false;
			}
			else if (height == -1 && (q.front().second == 1) && (q.front().first < 2 * L)) {
				valid = false;
			}
			else if (height == -1 && (q.front().first < L)) {
				valid = false;
			}
			if (!valid)
				break;
		}
		if (valid)
			cnt++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	check_row();
	check_col();
	cout << cnt;
	return 0;
}