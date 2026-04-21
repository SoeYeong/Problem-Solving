#include <iostream>
#include <vector>
using namespace std;

struct fireBall {
    int r, c;
    int m, s, d;
};
int N, M, K;
vector<fireBall> fb;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<int> map[51][51];

void move() {
    for (int i = 0; i < fb.size(); i++) {
        fb[i].r += dx[fb[i].d] * fb[i].s;
        fb[i].c += dy[fb[i].d] * fb[i].s;

        while (fb[i].r < 1) {
            fb[i].r += N;
        }
        while (fb[i].r > N) {
            fb[i].r -= N;
        }
        while (fb[i].c < 1) {
            fb[i].c += N;
        }
        while (fb[i].c > N) {
            fb[i].c -= N;
        }
    }
}
void count() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j].clear();
        }
    }

    for (int i = 0; i < fb.size(); i++) {
        map[fb[i].r][fb[i].c].push_back(i);
    }
}
void fire() {
    vector<fireBall> temp;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int sz = map[i][j].size();
            if (sz == 0) continue;
            if (sz == 1) {
                temp.push_back(fb[map[i][j][0]]);
                continue;
            }

            int mSum = 0, sSum = 0, remain = 0;
            for (int k = 0; k < sz; k++) {
                mSum += fb[map[i][j][k]].m;
                sSum += fb[map[i][j][k]].s;
                remain += fb[map[i][j][k]].d % 2;
            }
            if (mSum / 5 == 0) continue;

            for (int k = 0; k < 4; k++) {
                if (remain == sz || remain == 0)
                    temp.push_back({ i, j, mSum / 5, sSum / sz, 2 * k });
                else
                    temp.push_back({ i, j, mSum / 5, sSum / sz, 2 * k + 1 });
            }

        }
    }
    fb.clear();
    fb.assign(temp.begin(), temp.end());
}
void sum() {
    int sum = 0;
    for (int i = 0; i < fb.size(); i++) {
        sum += fb[i].m;
    }
    cout << sum;
}
void solution() {
    for (int i = 0; i < K; i++) {
        move();
        count();
        fire();
    }

    sum();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    int r, c, m, s, d;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        fb.push_back({ r,c,m,s,d });
    }

    solution();
    return 0;
}