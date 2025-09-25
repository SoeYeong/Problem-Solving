#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visit[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    pq.push({ 0, N });
    visit[N] = 1;

    while (!pq.empty()) {
        int time = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (now == K) {
            cout << time;
            break;
        }

        for (int next : {now - 1, now + 1, now * 2}) {
            if (next < 0 || next > 100000) continue;
            if (visit[next]) continue;
            visit[next] = 1;
            
            if (next == now * 2)
                pq.push({ time, next });
            else
                pq.push({ time + 1, next });
        }
    }

    return 0;
}