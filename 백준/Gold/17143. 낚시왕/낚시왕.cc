#include <iostream>
#include <vector>
using namespace std;

struct shark {
    int r, c;
    int s, d;   // 속력, 방향
    int z;  // 크기
    bool live = true;
};

int R, C, M;
vector<shark> sh;
int map[101][101];  // 상어 위치
int pos = 0;
int ans = 0;
int dr[4] = { -1,1,0,0 };   // 위, 아래, 오, 왼
int dc[4] = { 0,0,1,-1 };
int nextd[4] = { 1,0,3,2 };    // 방향 바꾸기

int findBig(vector<int> v) {
    int max_idx = 0;
    int max_size = 0;

    // 가장 큰 상어 번호
    for (int i = 0; i < v.size(); i++) {
        if (max_size < sh[v[i]].z) {
            max_size = sh[v[i]].z;
            max_idx = v[i];
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (max_idx == v[i]) continue;
        sh[v[i]].live = false;
    }

    return max_idx;
}
void move() {
    // 움직인 후의 상어 위치
    vector<int> temp[101][101];

    // 상어 이동
    for (int i = 1; i <= M; i++) {
        if (!sh[i].live) continue;

        int dis = sh[i].s;
        while (dis--) {
            int nr = sh[i].r + dr[sh[i].d];
            int nc = sh[i].c + dc[sh[i].d];

            if (nr < 1 || nr > R || nc < 1 || nc > C) {
                sh[i].d = nextd[sh[i].d];
            }
            sh[i].r += dr[sh[i].d];
            sh[i].c += dc[sh[i].d];
        }
        temp[sh[i].r][sh[i].c].push_back(i);
    }

    // 상어 위치 다시 표시
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            map[i][j] = 0;

            if (temp[i][j].size() == 1) {
                map[i][j] = temp[i][j][0];
            }
            else if (temp[i][j].size() > 1) {
                int num = findBig(temp[i][j]);
                map[i][j] = num;
            }
        }
    }
}
void catchShark () {
    int idx = 0;
    for (int i = 1; i <= R; i++) {
        if (map[i][pos]) {
            idx = map[i][pos];
            map[i][pos] = 0;
            break;
        }
    }

    ans += sh[idx].z;
    sh[idx].live = false;
}
void sol() {
    while (1) {
        pos++;
        if (pos > C) {
            break;
        }

        catchShark();
        move();
    }
    cout << ans;
}
void input() {
    cin >> R >> C >> M;

    // 0번 인덱스 처리
    sh.push_back({ 0,0,0,0,0,false });

    int r, c, s, d, z;
    for (int i = 1; i <= M; i++) {
        cin >> r >> c >> s >> d >> z;
        sh.push_back({ r,c,s,d - 1,z, true });
        map[r][c] = i;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    sol();

    return 0;
}