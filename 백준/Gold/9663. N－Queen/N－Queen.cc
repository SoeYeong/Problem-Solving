#include <iostream>
using namespace std;

int N;
int cnt;
bool col[15];
bool ru[30];
bool rd[30];

void dfs(int row) {
	if (row == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (col[i]) continue;
		if (ru[row + i]) continue;
		if (rd[N - row + i - 1]) continue;

		col[i] = true;
		ru[row + i] = true;
		rd[N - row + i - 1] = true;
		dfs(row + 1);
		col[i] = false;
		ru[row + i] = false;
		rd[N - row + i - 1] = false;
	}
}
int main() {
	cin >> N;

	dfs(0);
	cout << cnt;

	return 0;
}