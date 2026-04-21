#include <iostream>
#include <queue>
using namespace std;

int N, M;
int cnt[101];
int map[101];
void bfs() {
	queue <int> q;
	q.push(1);

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == 100) {
			cout << cnt[100];
			break;
		}

		for (int i = 1; i < 7; i++) {
			int next = pos + i;
			if (next > 100) continue;
			while (map[next] != 0) {
				next = map[next];
			}
			if (cnt[next]) continue;
			cnt[next] = cnt[pos] + 1;
			q.push(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		map[x] = y;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x] = y;
	}

	bfs();
	return 0;
}