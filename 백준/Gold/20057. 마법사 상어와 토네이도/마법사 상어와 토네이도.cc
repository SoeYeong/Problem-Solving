#include <iostream>
#include <vector>
using namespace std;

int N;
int map[500][500];
long long ans = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int sandx[4][9] = { {-1,1,-2,2,0,-1,1,-1,1}, {-1,-1,0,0,2,0,0,1,1},
                    {-1,1,-2,2,0,-1,1,-1,1}, {1,1,0,0,-2,0,0,-1,-1} };
int sandy[4][9] = { {1,1,0,0,-2,0,0,-1,-1}, {1,-1,2,-2,0,1,-1,1,-1},
                    {-1,-1,0,0,2,0,0,1,1}, {-1,1,-2,2,0,-1,1,-1,1} };
int ratio[9] = { 1,1,2,2,5,7,7,10,10 };
vector<int> moveCnt;

void spread(int r, int c, int d) {
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        int nr = r + sandx[d][i];
        int nc = c + sandy[d][i];

        sum += map[r][c] * ratio[i] / 100;
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            ans += map[r][c] * ratio[i] / 100;
            continue;
        }

        map[nr][nc] += map[r][c] * ratio[i] / 100;
    }

    int remain = map[r][c] - sum;
    map[r][c] = 0;
    if ((r + dx[d] < 0) || (r + dx[d] >= N) || (c + dy[d] < 0) || (c + dy[d] >= N)) {
        ans += remain;
        return;
    }
    map[r + dx[d]][c + dy[d]] += remain;
}
void move() {
    int d = 0;
    int r = N / 2, c = N / 2;
    for (int i = 0; i < moveCnt.size(); i++) {
        for (int j = 0; j < moveCnt[i]; j++) {
            spread(r + dx[d], c + dy[d], d);
            r += dx[d];
            c += dy[d];
        }
        d++;
        d %= 4;
    }
}
void solve() {
    for (int i = 1; i < N; i++) {
        moveCnt.push_back(i);
        moveCnt.push_back(i);
    }
    moveCnt.push_back(N - 1);
    move();
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    solve();
    return 0;
}