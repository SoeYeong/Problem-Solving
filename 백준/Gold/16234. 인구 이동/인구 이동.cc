#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, L, R;
int map[51][51];
bool visited[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool flag = true;
int sum;
int days = 0;

queue<pair<int, int>> q;
vector<pair<int, int>> v;

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(pair<int, int> start) {
	q.push(start);
	visited[start.first][start.second] = true;
	

	while (!q.empty()) {
		int tempx = q.front().first;
		int tempy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tempx + dx[i];
			int ny = tempy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (abs(map[tempx][tempy] - map[nx][ny]) < L || abs(map[tempx][tempy] - map[nx][ny]) > R) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
			v.push_back({ nx, ny });
			sum += map[nx][ny];
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (flag) {
		flag = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				
				if (!visited[i][j]) {
					sum = map[i][j];
					v.clear();
					v.push_back({ i,j });
					bfs({ i, j });
				}

				if (v.size() >= 2) {
					flag = true;
					for (int k = 0; k < v.size(); k++) {
						map[v[k].first][v[k].second] = sum / v.size();
					}
				}
			}
		}

		clear();
		if (flag) days++;
	}

	cout << days;
	return 0;
}