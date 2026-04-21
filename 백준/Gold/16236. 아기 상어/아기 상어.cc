#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, ans;
int map[20][20];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct pos {
    int x, y;
    int d = 0;
};
pos shark;
int ssize = 2;

vector<pos> fish;
bool compare(pos& a, pos& b) {
    if (a.d != b.d) {
        return a.d < b.d;
    }
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}
void bfs() {
    bool visit[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = false;
        }
    }

    queue<pos> q;
    q.push({ shark.x, shark.y, 0 });
    visit[shark.x][shark.y] = true;

    while (!q.empty()) {
        pos now = q.front();
        q.pop();

        pos next;
        for (int i = 0; i < 4; i++) {
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            next.d = now.d + 1;

            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N) continue;
            if (visit[next.x][next.y]) continue;
            if (map[next.x][next.y] > ssize) continue;
            if (map[next.x][next.y] < ssize && map[next.x][next.y]) {
                fish.push_back(next);
            }
            visit[next.x][next.y] = true;
            q.push(next);
        }
    }
}
void solve() {
    int eat = 0;
    while (1) {
        bfs();
        if (fish.empty()) {
            return;
        }
        sort(fish.begin(), fish.end(), compare);
        
        shark.x = fish[0].x;
        shark.y = fish[0].y;
        ans += fish[0].d;
        eat += 1;
        if (eat == ssize) {
            ssize += 1;
            eat = 0;
        }

        map[fish[0].x][fish[0].y] = 0;
        fish.clear();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark.x = i;
                shark.y = j;
                map[i][j] = 0;
            }
        }
    }

    solve();
    cout << ans;

    return 0;
}