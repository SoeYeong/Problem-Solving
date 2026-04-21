#include <iostream>
#include <queue>
using namespace std;

long long A, B;
int bfs() {
    queue<pair<long long, long long>> q;
    q.push({ A,1 });

    while (!q.empty()) {
        pair<long long, long long> now = q.front();
        q.pop();
        if (now.first == B) {
            return now.second;
        }
        if (now.first * 2 <= B) {
            q.push({ now.first * 2, now.second + 1 });
        }
        if (now.first * 10 + 1 <= B) {
            q.push({ now.first * 10 + 1, now.second + 1 });
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B;
    cout << bfs();

    return 0;
}