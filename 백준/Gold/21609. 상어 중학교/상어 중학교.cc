#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 9
using namespace std;

struct group {
    int r, c;   // 기준 블록
    int rainbow;
    int sz;
    vector<pair<int, int>> member;
};

int N, M, ans;
int map[21][21];
bool visit[21][21];
vector<group> g;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool compare(group& a, group& b) {
    if (a.sz != b.sz) return a.sz > b.sz;
    if (a.rainbow != b.rainbow) return a.rainbow > b.rainbow;
    if (a.r != b.r) return a.r > b.r;
    return a.c > b.c;
}

void init() {
    g.clear();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = 0;
        }
    }
}
void initVisitRainbow() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                visit[i][j] = false;
            }
        }
    }
}
void findGroup(int r, int c) {
    if (map[r][c] == -1 || map[r][c] == 0 || map[r][c] == INF) {
        return;
    }
    if (visit[r][c]) {
        return;
    }

    int num = map[r][c];
    int sz = 1, cnt = 0;
    visit[r][c] = true;

    vector<pair<int, int>> temp;
    temp.push_back({ r,c });

    queue<pair<int, int>> q;
    q.push({ r,c });

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.first + dx[i];
            int nc = now.second + dy[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (map[nr][nc] == -1 || map[nr][nc] == INF) continue;
            if (map[nr][nc] > 0 && map[nr][nc] != num) continue;
            if (visit[nr][nc]) continue;

            if (map[nr][nc] == 0) {
                cnt++;  // 무지개 블록 개수
            }
            visit[nr][nc] = true;
            sz++;
            q.push({ nr,nc });
            temp.push_back({ nr,nc });
        }
    }
    if (sz < 2) {
        return;
    }
    g.push_back({ r, c, cnt, sz, temp });
    initVisitRainbow();
}
void removeGroup() {
    group big = g[0];
    for (int i = 0; i < big.member.size(); i++) {
        int r = big.member[i].first;
        int c = big.member[i].second;

        map[r][c] = INF;
    }
}
void gravity() {
    for (int i = N - 1; i > 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (map[i][j] != INF) continue;

            int nr = i - 1;
            while (1) {
                if (nr < 0) {
                    break;
                }
                if (map[nr][j] == INF) {
                    nr--;
                }
                else {
                    break;
                }
            }

            if (nr < 0) continue;
            if (map[nr][j] == -1) {
                continue;
            }
            else {
                map[i][j] = map[nr][j];
                map[nr][j] = INF;
            }
        }
    }
}
void rotate() {
    int temp[21][21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = temp[j][N - 1 - i];
        }
    }
}
void autoplay() {
    sort(g.begin(), g.end(), compare);
    ans += g[0].sz * g[0].sz;

    removeGroup();
    gravity();
    rotate();
    gravity();
}
void solve() {
    while (1) {
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                findGroup(i, j);
            }
        }

        if (g.size() == 0) {
            break;
        }

        autoplay();
    }
    cout << ans;
}
void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    return 0;
}