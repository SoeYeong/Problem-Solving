#include <iostream>
#include <string>
#include <queue>
using namespace std;

int T;
string cube[6] = { "wwwwwwwww", "yyyyyyyyy",    // 위 아래
                   "rrrrrrrrr", "ooooooooo",    // 앞 뒤
                   "ggggggggg", "bbbbbbbbb" };   // 왼 오
char center[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };

int N;
queue <pair<char, char>> q;

void init() {
    cube[0] = "wwwwwwwww";
    cube[1] = "yyyyyyyyy";
    cube[2] = "rrrrrrrrr";
    cube[3] = "ooooooooo";
    cube[4] = "ggggggggg";
    cube[5] = "bbbbbbbbb";
}

void faceRotate(int idx, char dir) {
    if (dir == '+') {
        cube[idx] = cube[idx].substr(6, 2) + cube[idx].substr(0, 7);
    }
    else if (dir == '-') {
        cube[idx] = cube[idx].substr(2, 6) + cube[idx].substr(0, 3);
    }
}

void set8() {
    for (int i = 0; i < 6; i++) {
        cube[i][8] = cube[i][0];
    }
}

void set0() {
    for (int i = 0; i < 6; i++) {
        cube[i][0] = cube[i][8];
    }
}

void sideRotate(int idx, char d) {
    // UP
    if (idx == 0 && d == '-') {
        string temp = cube[2].substr(0, 3);
        cube[2].replace(0, 3, cube[4].substr(0, 3));
        cube[4].replace(0, 3, cube[3].substr(0, 3));
        cube[3].replace(0, 3, cube[5].substr(0, 3));
        cube[5].replace(0, 3, temp);
        set8();
    }
    else if (idx == 0 && d == '+') {
        string temp = cube[2].substr(0, 3);
        cube[2].replace(0, 3, cube[5].substr(0, 3));
        cube[5].replace(0, 3, cube[3].substr(0, 3));
        cube[3].replace(0, 3, cube[4].substr(0, 3));
        cube[4].replace(0, 3, temp);
        set8();
    }

    // DOWN
    else if (idx == 1 && d == '-') {
        string temp = cube[2].substr(4, 3);
        cube[2].replace(4, 3, cube[5].substr(4, 3));
        cube[5].replace(4, 3, cube[3].substr(4, 3));
        cube[3].replace(4, 3, cube[4].substr(4, 3));
        cube[4].replace(4, 3, temp);
    }
    else if (idx == 1 && d == '+') {
        string temp = cube[2].substr(4, 3);
        cube[2].replace(4, 3, cube[4].substr(4, 3));
        cube[4].replace(4, 3, cube[3].substr(4, 3));
        cube[3].replace(4, 3, cube[5].substr(4, 3));
        cube[5].replace(4, 3, temp);
    }

    // FRONT
    else if (idx == 2 && d == '+') {
        string temp = cube[0].substr(4, 3);
        cube[0].replace(4, 3, cube[4].substr(2, 3));
        cube[4].replace(2, 3, cube[1].substr(0, 3));
        cube[1].replace(0, 3, cube[5].substr(6, 3));
        cube[5].replace(6, 3, temp);

        cube[1][8] = cube[1][0];
        cube[5][0] = cube[5][8];
    }
    else if (idx == 2 && d == '-') {
        string temp = cube[0].substr(4, 3);
        cube[0].replace(4, 3, cube[5].substr(6, 3));
        cube[5].replace(6, 3, cube[1].substr(0, 3));
        cube[1].replace(0, 3, cube[4].substr(2, 3));
        cube[4].replace(2, 3, temp);

        cube[1][8] = cube[1][0];
        cube[5][0] = cube[5][8];
    }

    // BACK
    else if (idx == 3 && d == '+') {
        string temp = cube[0].substr(0, 3);
        cube[0].replace(0, 3, cube[5].substr(2, 3));
        cube[5].replace(2, 3, cube[1].substr(4, 3));
        cube[1].replace(4, 3, cube[4].substr(6, 3));
        cube[4].replace(6, 3, temp);

        cube[0][8] = cube[0][0];
        cube[4][0] = cube[4][8];
    }
    else if (idx == 3 && d == '-') {
        string temp = cube[0].substr(0, 3);
        cube[0].replace(0, 3, cube[4].substr(6, 3));
        cube[4].replace(6, 3, cube[1].substr(4, 3));
        cube[1].replace(4, 3, cube[5].substr(2, 3));
        cube[5].replace(2, 3, temp);

        cube[0][8] = cube[0][0];
        cube[4][0] = cube[4][8];
    }

    // LEFT
    else if (idx == 4 && d == '+') {
        string temp = cube[0].substr(6, 3);
        cube[0].replace(6, 3, cube[3].substr(2, 3));
        cube[3].replace(2, 3, cube[1].substr(6, 3));
        cube[1].replace(6, 3, cube[2].substr(6, 3));
        cube[2].replace(6, 3, temp);
        set0();
    }
    else if (idx == 4 && d == '-') {
        string temp = cube[2].substr(6, 3);
        cube[2].replace(6, 3, cube[1].substr(6, 3));
        cube[1].replace(6, 3, cube[3].substr(2, 3));
        cube[3].replace(2, 3, cube[0].substr(6, 3));
        cube[0].replace(6, 3, temp);
        set0();
    }

    // RIGHT
    else if (idx == 5 && d == '+') {
        string temp = cube[2].substr(2, 3);
        cube[2].replace(2, 3, cube[1].substr(2, 3));
        cube[1].replace(2, 3, cube[3].substr(6, 3));
        cube[3].replace(6, 3, cube[0].substr(2, 3));
        cube[0].replace(2, 3, temp);
        set0();
    }
    else if (idx == 5 && d == '-') {
        string temp = cube[0].substr(2, 3);
        cube[0].replace(2, 3, cube[3].substr(6, 3));
        cube[3].replace(6, 3, cube[1].substr(2, 3));
        cube[1].replace(2, 3, cube[2].substr(2, 3));
        cube[2].replace(2, 3, temp);
        set0();
    }
}

void rotate() {
    while (!q.empty()) {
        char face = q.front().first;
        char dir = q.front().second;
        q.pop();

        int idx = 0;
        switch (face) {
        case 'U':
            idx = 0;
            break;
        case 'D':
            idx = 1;
            break;
        case 'F':
            idx = 2;
            break;
        case 'B':
            idx = 3;
            break;
        case 'L':
            idx = 4;
            break;
        case 'R':
            idx = 5;
            break;
        }

        faceRotate(idx, dir);
        sideRotate(idx, dir);
    }
}

void print() {
    cout << cube[0][0] << cube[0][1] << cube[0][2] << "\n";
    cout << cube[0][7] << center[0] << cube[0][3] << "\n";
    cout << cube[0][6] << cube[0][5] << cube[0][4] << "\n";
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        init();
        cin >> N;
        for (int j = 0; j < N; j++) {
            char f, d;
            cin >> f >> d;
            q.push({ f, d });
        }
        rotate();
        print();
    }

    return 0;
}