#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos {
    int r, c;
};
string map[13];
int answer;
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
int visit[13][7];
vector<vector<pos>> groups;

void init() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            visit[i][j] = 0;
        }
    }
    groups.clear();
}
void gravity() {
    for (int j = 0; j < 6; j++) {
        for (int i = 11; i >= 0; i--) {
            if (map[i][j] == '.') continue;

            for (int k = i + 1; k < 12; k++) {
                if (map[k][j] == '.') {
                    map[k][j] = map[k - 1][j];
                    map[k - 1][j] = '.';
                }
            }
        }
    }
}
void findGroup(int r, int c) {
    vector<pos> v;
    queue<pos> q;
    v.push_back({ r, c });
    q.push({ r, c });

    visit[r][c] = 1;
    char color = map[r][c];

    while (!q.empty()) {
        pos now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
            if (visit[nr][nc]) continue;
            if (map[nr][nc] != color) continue;

            visit[nr][nc] = 1;
            q.push({ nr, nc });
            v.push_back({ nr, nc });
        }
    }

    if (v.size() >= 4) {
        groups.push_back(v);
    }
}
void deleteGroup() {
    for (int i = 0; i < groups.size(); i++) {
        vector<pos> v = groups[i];

        for (pos p : v) {
            map[p.r][p.c] = '.';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 12; i++) {
        cin >> map[i];
    }

    while (1) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] == '.') continue;
                if (visit[i][j]) continue;

                findGroup(i, j);
            }
        }
        if (groups.size() == 0) {
            break;
        }
        // group 삭제
        deleteGroup();

        // 중력 작용
        gravity();

        answer++;
        init();
    }

    cout << answer;

    return 0;
}