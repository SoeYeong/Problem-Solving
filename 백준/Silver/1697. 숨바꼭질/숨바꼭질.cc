#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visit[100001];
void bfs(int n) {
	queue <pair<int, int>> q;
	q.push({ n,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == K) {
			cout << cnt;
			break;
		}
		if (x + 1 >= 0 && x + 1 < 100001) {
			if (!visit[x + 1]) {
				visit[x + 1] = true;
				q.push({ x + 1, cnt + 1 });
			}
		}
		if (x - 1 >= 0 && x - 1 < 100001) {
			if (!visit[x - 1]) {
				visit[x - 1] = true;
				q.push({ x - 1, cnt + 1 });
			}
		}
		if (x * 2 >= 0 && x * 2 < 100001) {
			if (!visit[x * 2]) {
				visit[x * 2] = true;
				q.push({ x * 2, cnt + 1 });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	visit[N] = true;
	bfs(N);
	return 0;
}