#include <iostream>
#include <queue>

using namespace std;

string map[10];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
int visit[10][10];
queue <pair<int, int>> q;

void bfs(int i, int j) {
    q.push({ i, j });
    visit[i][j] = 1;

    while (!q.empty()) {
        int nowr = q.front().first;
        int nowc = q.front().second;
        q.pop();

        if (map[nowr][nowc] == 'L') {
            cout << visit[nowr][nowc] - 2;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nextr = nowr + dr[d];
            int nextc = nowc + dc[d];

            if (nextr < 0 || nextc < 0 || nextr >= 10 || nextc >= 10) continue;
            if (visit[nextr][nextc]) continue;
            if (map[nextr][nextc] == 'R') continue;
            visit[nextr][nextc] = visit[nowr][nowc] + 1;
            q.push({ nextr, nextc });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'B') {
                bfs(i, j);
                return 0;
            }
        }
    }
    
    return 0;
}