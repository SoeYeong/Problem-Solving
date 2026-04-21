#include <iostream>

using namespace std;

int N, M;
int ix, iy, cmd_n;
int cmd[1000];
int map[20][20];
int dice[6];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void Movement(int cmd) {
    //동
    if (cmd == 0) {
        int temp = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = temp;
    }
    //서
    if (cmd == 1) {
        int temp = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[0];
        dice[0] = temp;
    }
    //북
    if (cmd == 2) {
        int temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
    //남
    if (cmd == 3) {
        int temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
}

void throw_dice() {
    for (int i = 0; i < cmd_n; i++) {
        int n = cmd[i] - 1;

        int xx = ix + dx[n];
        int yy = iy + dy[n];
        if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
        ix = xx;
        iy = yy;

        Movement(n);
        if (map[ix][iy] == 0) {
            map[ix][iy]= dice[1];
        }
        else {
            dice[1] = map[ix][iy];
            map[ix][iy] = 0;
        }

        cout << dice[0] << "\n";
    }
}


int main() {
    cin >> N >> M >> ix >> iy >> cmd_n;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < cmd_n; i++) {
        cin >> cmd[i];
    }

    throw_dice();
    return 0;
}