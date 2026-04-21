#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Fish {
    int dir;
    int x, y;
    bool live;
};

int map[4][4];
vector<Fish> fish(17);  // 물고기 정보
Fish shark = { 0,0,0,true };
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int ans;

bool fishMovable(int num) {
    int cnt = 0;
    int nd = fish[num].dir;
    while (1) {
        if (cnt == 8) {
            break;
        }

        cnt++;
        int nx = fish[num].x + dx[nd];
        int ny = fish[num].y + dy[nd];

        if (nx < 0 || nx > 3 || ny < 0 || ny > 3 || map[nx][ny] == 100) {
            nd++;
            if (nd == 9) {
                nd = 1;
            }

            continue;
        }

        fish[num].dir = nd;
        return true;
    }
    return false;
}
void fishMove() {
    for (int i = 1; i < 17; i++) {
        if (!fish[i].live) continue;
        if (!fishMovable(i)) continue;
        
        int change = map[fish[i].x + dx[fish[i].dir]][fish[i].y + dy[fish[i].dir]];
        if (change == 0) {
            map[fish[i].x][fish[i].y] = 0;
            fish[i].x += dx[fish[i].dir];
            fish[i].y += dy[fish[i].dir];
            map[fish[i].x][fish[i].y] = i;
            continue;
        }

        fish[change].x = fish[i].x;
        fish[change].y = fish[i].y;
        fish[i].x += dx[fish[i].dir];
        fish[i].y += dy[fish[i].dir];

        map[fish[i].x][fish[i].y] = i;
        map[fish[change].x][fish[change].y] = change;
    }
}
bool sharkMovable(vector<pair<int, int>>& movable) {
    bool check = false;
    int nx = shark.x;
    int ny = shark.y;

    while (1) {
        nx += dx[shark.dir];
        ny += dy[shark.dir];

        if (nx < 0 || nx > 3 || ny < 0 || ny > 3) {
            break;
        }
        if (map[nx][ny] > 0) {
            check = true;
            movable.push_back({ nx, ny });
        }
    }
    return check;
}
void sharkMove(int result) {
    fishMove();
    vector<pair<int, int>> movable;

    if (!sharkMovable(movable)) {
        ans = max(ans, result);
        return;
    }

    for (int k = 0; k < movable.size(); k++) {
        vector<Fish> fishBackup(fish);
        Fish sharkBackup = shark;
        int mapBackup[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                mapBackup[i][j] = map[i][j];
            }
        }

        // 상어 이동
        map[shark.x][shark.y] = 0;
        shark.x = movable[k].first;
        shark.y = movable[k].second;
        int num = map[shark.x][shark.y];
        shark.dir = fish[num].dir;
        fish[num].live = false;
        map[shark.x][shark.y] = 100;

        sharkMove(result + num);

        copy(fishBackup.begin(), fishBackup.end(), fish.begin());
        shark = sharkBackup;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                map[i][j] = mapBackup[i][j];
            }
        }
    }
}
void solve() {
    int num = map[0][0];
    shark.dir = fish[num].dir;;
    fish[num].live = false;
    map[0][0] = 100;

    sharkMove(num);
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            map[i][j] = a;
            fish[a] = { b, i, j, true };
        }
    }

    solve();
    return 0;
}