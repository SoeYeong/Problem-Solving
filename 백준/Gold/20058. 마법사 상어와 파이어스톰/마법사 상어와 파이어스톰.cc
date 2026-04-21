#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N, Q;
int L[1000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ice[64][64];
bool visit[64][64];
int cnt[64][64];

void rotate(int x, int y, int l) {
    int temp[64][64];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            temp[j][l - 1 - i] = ice[x + i][y + j];
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            ice[x + i][y + j] = temp[i][j];
        }
    }
}
void fireStorm(int l) {
    // 회전
    for (int i = 0; i < N; i += l) {
        for (int j = 0; j < N; j += l) {
            rotate(i, j, l);
        }
    }

    // 얼음 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt[i][j] = 0;
            if (ice[i][j] == 0) continue;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (ice[nx][ny] == 0) continue;
                cnt[i][j]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ice[i][j] == 0) continue;
            if (cnt[i][j] < 3) {
                ice[i][j]--;
            }
        }
    }
}
void sum() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += ice[i][j];
        }
    }
    cout << sum << "\n";
}
int bfs(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({ x, y });
    visit[x][y] = true;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visit[nx][ny]) continue;
            if (ice[nx][ny] == 0) continue;
            visit[nx][ny] = true;
            cnt++;
            q.push({ nx, ny });
        }
    }
    return cnt;
}
void findMax() {
    int maxx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j]) continue;
            if (ice[i][j] == 0) continue;
            maxx = max(maxx, bfs(i, j));
        }
    }
    cout << maxx;
}
void solve() {
    for (int i = 0; i < Q; i++) {
        fireStorm(L[i]);
    }

    sum();
    findMax();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, l;
    cin >> n >> Q;
    N = pow(2, n);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ice[i][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> l;
        L[i] = pow(2, l);
    }

    solve();

    return 0;
}