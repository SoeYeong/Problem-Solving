#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K, L;
int map[101][101];      // apple = 1, snake = 2

int dx[4] = { 0, 1, 0, -1 };    // 오 아래 왼 위
int dy[4] = { 1, 0, -1, 0 };
int dir;            // direction
int t = 0;          // time
int idx;

deque <pair<int, int>> dq;
vector <pair<int, char>> v;
int X;
char C;


void changeDir(char c){
    if (c == 'D') {
        dir++;
        if (dir == 4) dir = 0;
    }
    else {
        dir--;
        if (dir < 0) dir = 3;
    }
}

bool isValid(int x, int y) {
    if (x <= 0 || x > N || y <= 0 || y > N) return false;
    if (map[x][y] == 2) return false;
    return true;
}

void move() {
    while (1) {
        t++;
        int hx = dq.front().first;
        int hy = dq.front().second;
        int x = hx + dx[dir];
        int y = hy + dy[dir];
        
        if (!isValid(x, y)) break;

        if(map[x][y] == 0) {
            map[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        dq.push_front({ x, y });
        map[x][y] = 2;

        if (idx < v.size()) {
            if (t == v[idx].first) {
                changeDir( v[idx].second );
                idx++;
            }
        }

    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    map[1][1] = 2;
    dq.push_back({ 1, 1 });

    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> X >> C;
        v.push_back({ X, C });
    }
    move();
    cout << t;
    return 0;
}