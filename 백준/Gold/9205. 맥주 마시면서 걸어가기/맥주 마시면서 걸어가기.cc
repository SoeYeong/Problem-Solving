#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int T, N;
struct pos {
    int x, y;
};
pos home, fest;
vector<pos> store;
bool visit[101];

void init() {
    store.clear();
    for (int i = 0; i < N; i++) {
        visit[i] = false;
    }
}
bool bfs() {
    queue<pos> q;
    q.push({ home.x, home.y });

    while (!q.empty()) {
        pos now = q.front();
        q.pop();

        if (abs(now.x - fest.x) + abs(now.y - fest.y) <= 1000) return true;
        for (int i = 0; i < N; i++) {
            if (visit[i]) continue;
            if (abs(now.x - store[i].x) + abs(now.y - store[i].y) <= 1000) {
                visit[i] = true;
                q.push({ store[i].x, store[i].y });
            }
        }
    }
    return false;
}
void solution() {
    bool check = bfs();
    if (check)
        cout << "happy\n";
    else
        cout << "sad\n";

    init();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    int tx, ty;
    while (T--) {
        cin >> N;
        cin >> home.x >> home.y;
        for (int i = 0; i < N; i++) {
            cin >> tx >> ty;
            store.push_back({ tx,ty });
        }
        cin >> fest.x >> fest.y;

        solution();
    }

    return 0;
}