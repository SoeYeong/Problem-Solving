#include <iostream>
#include <queue>
using namespace std;
//1966번
int t, n, m;
int cnt, priority;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		queue<pair<int, int>> q;
		priority_queue <int> pq;
		cnt = 0;

		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> priority;
			q.push({ j, priority });
			pq.push(priority);
		}

		while (1) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();

			if (val == pq.top()) {
				pq.pop();
				cnt++;
				if (idx == m) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push({ idx, val });
			}
		}
	}
}