#include <iostream>
#include <algorithm>

#define MAX 1000000001
using namespace std;

int N, M, a, b;
int arr[100001];
int max_tree[300000], min_tree[300000];
int s = 1;
void init() {
    while (s < N) {
        s *= 2;
    }
    for (int i = s; i < s + N; i++) {
        max_tree[i] = arr[i - s + 1];
        min_tree[i] = arr[i - s + 1];
    }
    for (int i = s + N; i < s * 2; i++) {
        min_tree[i] = MAX;
    }
    for (int i = s - 1; i > 0; i--) {
        max_tree[i] = max(max_tree[i * 2], max_tree[i * 2 + 1]);
        min_tree[i] = min(min_tree[i * 2], min_tree[i * 2 + 1]);
    }
}
pair<int, int> find(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return { MAX,0 };
    }
    if (qLeft <= left && right <= qRight) {
        return { min_tree[node], max_tree[node]};
    }
    int mid = (left + right) / 2;
    pair<int, int> l, r;
    l = find(left, mid, node * 2, qLeft, qRight);
    r = find(mid + 1, right, node * 2 + 1, qLeft, qRight);
    return { min(l.first, r.first), max(l.second, r.second) };
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init();
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        pair<int, int> ans = find(1, s, 1, a, b);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}