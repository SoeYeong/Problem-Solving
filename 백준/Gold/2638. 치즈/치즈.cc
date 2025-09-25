#include <iostream>
#include <queue>

#define IN 0
#define CHEESE 1
#define OUT 2
using namespace std;

int N, M, T;
int map[101][101];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

void findOut(int r, int c) {
    int visit[101][101] = { 0, };

    queue<pair<int, int>> q;
    q.push({ r, c });
    visit[r][c] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextr = now.first + dr[i];
            int nextc = now.second + dc[i];

            if (nextr < 0 || nextr >= N || nextc < 0 || nextc >= M) continue;
            if (visit[nextr][nextc]) continue;
            if (map[nextr][nextc] == CHEESE) continue;

            q.push({ nextr, nextc });
            visit[nextr][nextc] = 1;
            map[nextr][nextc] = OUT;
        }
    }
}
bool findCheese() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == CHEESE) {
                return true;
            }
        }
    }
    return false;
}
void meltCheese() {
    queue<pair<int, int>> q;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (map[i][j] != CHEESE) continue;
            int cnt = 0;

            for (int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];
                if (map[r][c] == OUT)
                    cnt++;
            }

            if (cnt >= 2)
                q.push({ i,j });
        }
    }

    while (!q.empty()) {
        map[q.front().first][q.front().second] = OUT;
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        if (!findCheese()) {
            cout << T;
            break;
        }
        
        findOut(0,0);
        meltCheese();
        T++;
    }

    return 0;
}