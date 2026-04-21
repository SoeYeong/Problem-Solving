#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int T, l;
int sr, sc, er, ec;
int visit[301][301];
int dr[8] = { -1,-2,-2,-1,1,2,2,1 };
int dc[8] = { -2,-1,1,2,-2,-1,1,2 };
void init() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            visit[i][j] = 0;
        }
    }
}
void bfs() {
    queue<pair<int, int>> q;
    q.push({ sr,sc });
    visit[sr][sc] = 1;

    while (!q.empty()) {
        int nowr = q.front().first;
        int nowc = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextr = nowr + dr[i];
            int nextc = nowc + dc[i];
            if (nextr < 0 || nextr >= l || nextc < 0 || nextc >= l) continue;
            if (visit[nextr][nextc]) continue;
            visit[nextr][nextc] = visit[nowr][nowc] + 1;
            q.push({ nextr,nextc });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> l;
        cin >> sr >> sc >> er >> ec;
        if (sr == er && sc == ec) {
            cout << "0\n";
            continue;
        }

        bfs();
        cout << visit[er][ec] - 1 << '\n';
        init();
    }

    return 0;
}