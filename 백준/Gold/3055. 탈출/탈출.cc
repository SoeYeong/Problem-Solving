#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[51][51];
int visit[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dr, dc, sr, sc;	// 비버, 고슴도치 위치

struct info {
	int r, c;
	char type;
};
queue <info> q;
bool map_check(int r, int c) {
	//범위, 물, 돌 확인
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	else if (map[r][c] == '*' || map[r][c] == 'X') return false;
	return true;
}
void bfs() {
	q.push({ sr, sc, 'S' });

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		if (map[now.r][now.c] == 'D') {
			return;
		}
		else if (now.type == '*') {
			for (int i = 0; i < 4; i++) {
				int nwr = now.r + dx[i];
				int nwc = now.c + dy[i];

				if (!map_check(nwr, nwc)) continue;
				if (map[nwr][nwc] == 'D') continue;
				map[nwr][nwc] = '*';
				q.push({ nwr, nwc, '*' });
			}
		}
		else if (now.type == 'S') {
			for (int i = 0; i < 4; i++) {
				int nsr = now.r + dx[i];
				int nsc = now.c + dy[i];
				
				if (!map_check(nsr, nsc)) continue;
				if (visit[nsr][nsc]) continue;
				visit[nsr][nsc] = visit[now.r][now.c] + 1;
				q.push({ nsr, nsc, 'S' });
			}
		}
	}
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'D') {
				dr = i, dc = j;
			}
			else if (map[i][j] == 'S') {
				sr = i, sc = j;
				visit[i][j] = 1;
			}
			else if (map[i][j] == '*') {
				q.push({ i, j, '*' });
			}
		}
	}

	bfs();
	if (visit[dr][dc]) {
		cout << visit[dr][dc] - 1;
	}
	else {
		cout << "KAKTUS";
	}
	return 0;
}
