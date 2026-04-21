#include <iostream>
using namespace std;

int N;
int arr[12];
int op[4];
int maxx = -21e8;
int minn = 21e8;

void dfs(int level, int result) {
	if (level == N) {
		maxx = max(result, maxx);
		minn = min(result, minn);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;

		op[i]--;
		if (i == 0) {
			dfs(level + 1, result + arr[level]);
		}
		else if (i == 1) {
			dfs(level + 1, result - arr[level]);
		}
		else if (i == 2) {
			dfs(level + 1, result * arr[level]);
		}
		else {
			dfs(level + 1, result / arr[level]);
		}
		op[i]++;
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(1, arr[0]);
	cout << maxx << "\n" << minn;
	return 0;
}