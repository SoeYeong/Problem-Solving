#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dist[100001], cnt[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    queue<int> q;
    q.push(N);
    dist[N] = 1;
    cnt[N] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : {now - 1, now + 1, now * 2}) {
            if (next < 0 || next > 100000) continue;

            // 처음 방문
            if (dist[next] == 0) {
                dist[next] = dist[now] + 1;
                cnt[next] = cnt[now];
                q.push(next);
            }

            // 이미 방문했던 곳
            else {
                if (dist[next] == dist[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    cout << dist[K] - 1 << "\n" << cnt[K];

    return 0;
}