#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int map[21][21];
vector<int> seq;
int like[401][4];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int score[5] = { 0,1,10,100,1000 };

struct info {
    int empty, like, r, c;
};
struct  compare {
    bool operator() (info& a, info& b) {
        if (a.like != b.like) {
            return a.like < b.like;
        }
        if (a.empty != b.empty) {
            return a.empty < b.empty;
        }
        if (a.r != b.r) {
            return a.r > b.r;
        }
        return a.c > b.c;
    }
};

int countEmpty(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        if (map[nx][ny]) continue;
        cnt++;
    }
    return cnt;
}
int countLike(int num, int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        if (map[nx][ny] == 0) continue;
        for (int k = 0; k < 4; k++) {
            if (map[nx][ny] == like[num][k]) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
void sit() {
    for (int i = 0; i < seq.size(); i++) {
        priority_queue<info, vector<info>, compare> pq;
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (map[j][k]) continue;
                int e = countEmpty(j, k);
                int l = countLike(seq[i], j, k);
                pq.push({ e,l,j,k });
            }
        }
        int r = pq.top().r;
        int c = pq.top().c;
        map[r][c] = seq[i];
    }
}
void sum() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += score[countLike(map[i][j], i, j)];
        }
    }
    cout << ans;
}
void solution() {
    sit();
    sum();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int num;
    for (int i = 0; i < N * N; i++) {
        cin >> num;
        seq.push_back(num);
        cin >> like[num][0] >> like[num][1] >> like[num][2] >> like[num][3];
    }

    solution();

    return 0;
}