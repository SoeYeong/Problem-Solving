#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//2667
int N;
int map[25][25];
int visit[25][25];
int cnt;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> answer;
void bfs(int i, int j) {
	queue <pair<int, int>> q;
	q.push({ i, j });
	visit[i][j] = 1;
	cnt = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
			if (!map[xx][yy]) continue;
			if (visit[xx][yy]) continue;
			visit[xx][yy] = 1;
			cnt++;
			q.push({ xx, yy });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j]) {
				bfs(i, j);
				answer.push_back(cnt);
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (auto a : answer) {
		cout << a << "\n";
	}
	return 0;
}