#include <iostream>
#include <vector>
using namespace std;

struct _cmd {
    int d, s;   // 방향, 거리
};
struct pos {
    int r, c;
};

int N, M;
int dr[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dc[9] = { 0,-1,-1,0,1,1,1,0,-1 };
pair<int, bool> map[51][51];
vector<pos> cloud;
vector<_cmd> cmd;

void move(int idx) {
    // 구름 이동
    for (int i = 0; i < cloud.size(); i++) {
        int nr = cloud[i].r + dr[cmd[idx].d] * cmd[idx].s;
        int nc = cloud[i].c + dc[cmd[idx].d] * cmd[idx].s;
        
        while (nr < 1) {
            nr += N;
        }
        while (nr > N) {
            nr -= N;
        }
        while (nc < 1) {
            nc += N;
        }
        while (nc > N) {
            nc -= N;
        }

        cloud[i].r = nr;
        cloud[i].c = nc;
    }

    // 비 내리기
    for (int i = 0; i < cloud.size(); i++) {
        map[cloud[i].r][cloud[i].c].first += 1;
        map[cloud[i].r][cloud[i].c].second = true;
    }
}
void copyWater() {
    for (int i = 0; i < cloud.size(); i++) {
        int cnt = 0;
        for (int d = 2; d < 9; d += 2) {
            int nr = cloud[i].r + dr[d];
            int nc = cloud[i].c + dc[d];

            if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if (map[nr][nc].first == 0) continue;
            cnt++;
        }
        map[cloud[i].r][cloud[i].c].first += cnt;
    }

    cloud.clear();
}
void makeCloud() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j].first >= 2 && !map[i][j].second) {
                map[i][j].first -= 2;
                cloud.push_back({ i, j });
            }
            map[i][j].second = false;
        }
    }
}
void sum() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum += map[i][j].first;
        }
    }
    cout << sum;
}
void solve() {
    cloud.push_back({ N,1 });
    cloud.push_back({ N,2 });
    cloud.push_back({ N-1,1 });
    cloud.push_back({ N-1,2 });

    for (int i = 0; i < M; i++) {
        // 구름 이동
        move(i);

        // 물 복사
        copyWater();

        // 구름 생성
        makeCloud();
    }
    sum();
}
void input() {
    int d, s;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j].first;
            map[i][j].second = false;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        cmd.push_back({ d,s });
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    return 0;
}