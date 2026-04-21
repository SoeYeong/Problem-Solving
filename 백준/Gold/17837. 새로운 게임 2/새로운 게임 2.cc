#include <iostream>
#include <vector>
using namespace std;

struct info {
    int x, y;
    int dir;
};
int N, K;
int map[13][13];    // 0: W, 1: R, 2: B
vector<int> v[13][13];
info horse[11];
int dx[5] = { 0,0,0,-1,1 };     // 오, 왼, 위, 아래
int dy[5] = { 0,1,-1,0,0 };
bool stop = false;

void red(int idx) {
    int x = horse[idx].x;
    int y = horse[idx].y;
    int nx = x + dx[horse[idx].dir];
    int ny = y + dy[horse[idx].dir];

    // 현재 말 위에 아무것도 없는 경우
    if (v[x][y].back() == idx) {
        v[x][y].pop_back();
        horse[idx].x = nx;
        horse[idx].y = ny;
        v[nx][ny].push_back(idx);

        return;
    }

    // 있는 경우
    int i;
    for (i = 0; i < v[x][y].size(); i++) {
        if (v[x][y][i] == idx) {
            break;
        }
    }
    while(v[x][y].size() > i) {
        int temp = v[x][y].back();
        horse[temp].x = nx;
        horse[temp].y = ny;
        v[nx][ny].push_back(temp);
        v[x][y].pop_back();
    }
}
void white(int idx) {
    int x = horse[idx].x;
    int y = horse[idx].y;
    int nx = x + dx[horse[idx].dir];
    int ny = y + dy[horse[idx].dir];

    // 현재 말 위에 아무것도 없는 경우
    if (v[x][y].back() == idx) {
        v[x][y].pop_back();
        horse[idx].x = nx;
        horse[idx].y = ny;
        v[nx][ny].push_back(idx);

        return;
    }

    // 있는 경우
    int i;
    for (i = 0; i < v[x][y].size(); i++) {
        if (v[x][y][i] == idx) {
            break;
        }
    }
    for (int k = i; k < v[x][y].size(); k++) {
        int temp = v[x][y][k];
        horse[temp].x = nx;
        horse[temp].y = ny;
        v[nx][ny].push_back(temp);
    }
    while (v[x][y].size() > i) {
        v[x][y].pop_back();
    }
}
void blue(int idx) {
    // 방향 바꾸기
    if (horse[idx].dir % 2) {
        horse[idx].dir += 1;
    }
    else {
        horse[idx].dir -= 1;
    }

    // 다음 칸 이동
    int x = horse[idx].x;
    int y = horse[idx].y;
    int nx = x + dx[horse[idx].dir];
    int ny = y + dy[horse[idx].dir];

    // 파란 칸 or 범위 벗어날 경우
    if (nx < 1 || nx > N || ny < 1 || ny > N || map[nx][ny] == 2) {
        return;
    }
    if (map[nx][ny] == 1) {
        red(idx);
        return;
    }
    white(idx);
}
bool check() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i][j].size() >= 4)
                return true;
        }
    }
    return false;
}
void move() {
    for (int i = 1; i <= K; i++) {
        int nx = horse[i].x + dx[horse[i].dir];
        int ny = horse[i].y + dy[horse[i].dir];

        if (nx < 1 || nx > N || ny < 1 || ny > N) {
            blue(i);
        }
        else if (map[nx][ny] == 2) {
            blue(i);
        }
        else if (map[nx][ny] == 0) {
            white(i);
        }
        else {
            red(i);
        }

        stop = check();
        if (stop) {
            return;
        }
    }
}

void solution() {
    int turn = 1;
    while (1) {
        if (turn > 1000) {
            cout << -1;
            return;
        }

        move();
        if (stop) {
            cout << turn;
            return;
        }
        turn++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= K; i++) {
        cin >> horse[i].x >> horse[i].y >> horse[i].dir;
        v[horse[i].x][horse[i].y].push_back(i);
    }

    solution();
    return 0;
}