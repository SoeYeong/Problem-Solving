// DP
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1002
using namespace std;

int N, W;
int pos[MAX][2];
// 경찰차1이 f, 경찰차2가 s 사건 위치에 있을 때 
// 앞으로 이동하게 되는 최소 거리
int dp[MAX][MAX];
vector<int> v;
int dist(int a, int b) {
    return abs(pos[a][0] - pos[b][0]) + abs(pos[a][1] - pos[b][1]);
}
int mem(int f, int s) {
    if (f == W + 1 || s == W + 1) return 0;

    int ret = dp[f][s];
    if (ret != 0) return ret;

    int next = max(f, s) + 1;
    int p1 = mem(next, s) + dist(f, next);
    int p2 = mem(f, next) + dist(s, next);
    ret = min(p1, p2);
    return dp[f][s] = ret;
}
void path(int f, int s) {
    if (f == W + 1 || s == W + 1) {
        for (auto n : v) {
            cout << n << '\n';
        }
        return;
    }

    int next = max(f, s) + 1;
    int p1 = mem(next, s) + dist(f, next);
    int p2 = mem(f, next) + dist(s, next);
    if (p1 < p2) {
        v.push_back(1);
        path(next, s);
    }
    else {
        v.push_back(2);
        path(f, next);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> W;

    pos[0][0] = 1, pos[0][1] = 1;   // 경찰차1 위치
    pos[1][0] = N, pos[1][1] = N;   // 경찰차2 위치
    for (int i = 2; i <= W + 1; i++) {
        cin >> pos[i][0] >> pos[i][1];
    }

    cout << mem(0, 1) << '\n';
    path(0, 1);
    return 0;
}