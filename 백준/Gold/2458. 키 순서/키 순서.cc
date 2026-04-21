// 방법 1 (dfs)
// dfs: 자신보다 큰 사람
// 간선 거꾸로 -> dfs : 자신보다 작은 사람

// 방법 2 (플로이드-워셜)
// 자신보다 작은 사람 + 큰 사람 == N-1

#include <iostream>
#include <vector>
#define MAX 501
using namespace std;

int N, M, a, b;
vector<int> small[MAX];
vector<int> tall[MAX];
bool svisit[MAX], tvisit[MAX];
int sCnt[MAX], tCnt[MAX];
int ans;
void sdfs(int start, int now) {
    if (small[now].size() == 0) return;

    for (auto i : small[now]) {
        if (svisit[i]) continue;
        svisit[i] = true;
        sCnt[start]++;
        sdfs(start, i);
    }
}
void tdfs(int start, int now) {
    if (tall[now].size() == 0) return;

    for (auto i : tall[now]) {
        if (tvisit[i]) continue;
        tvisit[i] = true;
        tCnt[start]++;
        tdfs(start, i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    while (M--) {
        cin >> a >> b;
        tall[a].push_back(b);
        small[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        fill_n(svisit, N + 1, false);
        fill_n(tvisit, N + 1, false);

        svisit[i] = true;
        sdfs(i, i);

        tvisit[i] = true;
        tdfs(i, i);
    }
    for (int i = 1; i <= N; i++) {
        if (sCnt[i] + tCnt[i] == N - 1) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}