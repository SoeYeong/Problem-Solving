#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B;
int indegree[32001];    // 진입 차수
vector<int> v[32001];   // 진출 노드 번호
void solve() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            cout << i << ' ';
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            indegree[v[now][i]]--;
            if (indegree[v[now][i]] == 0) {
                q.push(v[now][i]);
                cout << v[now][i] << ' ';
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        indegree[B]++;
        v[A].push_back(B);
    }
    solve();

    return 0;
}