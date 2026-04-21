#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

int F, S, G, U, D;
int building[MAX + 1];
int dd[2];
queue<int> q;
void bfs() {
    building[S] = 1;
    q.push(S);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == G)
            break;

        for (int i = 0; i < 2; i++) {
            int next = now + dd[i];
            if (next < 1 || next > F) continue;
            if (building[next]) continue;
            building[next] = building[now] + 1;
            q.push(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    dd[0] = U; 
    dd[1] = -D;

    bfs();
    if (building[G])
        cout << building[G] - 1;
    else
        cout << "use the stairs";

    return 0;
}