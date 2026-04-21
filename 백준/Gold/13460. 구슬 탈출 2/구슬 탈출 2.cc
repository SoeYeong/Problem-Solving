#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[10][10];
bool visit[10][10][10][10];
int dx[4] = { 0, 0, -1, 1 };    //오 왼 위 아래
int dy[4] = { 1, -1, 0, 0 };
struct step {
    int rx, ry;
    int bx, by;
    int cnt;
};

queue<step> q;

void move(int& x, int& y, int& distance, int i) {
    while (map[x+dx[i]][y+dy[i]] != '#' && map[x][y] != 'O') {
        x += dx[i];
        y += dy[i];
        distance += 1;
    }
}

void bfs(int rx, int ry, int bx, int by) {
    q.push({ rx, ry, bx, by, 0 });
    visit[rx][ry][bx][by] = true;

    while (!q.empty()) {
        int rxx = q.front().rx;
        int ryy = q.front().ry;
        int bxx = q.front().bx;
        int byy = q.front().by;
        int count = q.front().cnt;
        q.pop();

        if (count >= 10) break;

        for (int i = 0; i < 4; i++) {
            int nrx = rxx, nry = ryy, nbx = bxx, nby = byy;
            int rc = 0, bc = 0;
            int ncount = count + 1;

            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);

            if (map[nbx][nby] == 'O') continue;
            if (map[nrx][nry] == 'O') {
                cout << ncount;
                return;
            }

            if (nrx == nbx && nry == nby) {
                if (rc > bc) {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (visit[nrx][nry][nbx][nby]) continue;
            visit[nrx][nry][nbx][nby] = true;
            q.push({ nrx, nry, nbx, nby, ncount });
        }
    }
    cout << -1;
}

int main() {
    cin >> N >> M;

    int Rx = 0, Ry = 0, Bx = 0, By = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                Rx = i;
                Ry = j;
            }
            else if (map[i][j] == 'B') {
                Bx = i;
                By = j;
            }
        }
    }

    bfs(Rx, Ry, Bx, By);
    return 0;
}