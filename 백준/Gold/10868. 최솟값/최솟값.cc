#include <iostream>
#include <algorithm>

#define INT_MAX 0x7fffffff
#define MAX 100001
using namespace std;

int N, M, a, b;
int num[MAX];
int tree[4 * MAX];
void init(int start, int end, int node) {
    if (start == end) {
        tree[node] = num[start];
        return;
    }
    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query(int start, int end, int node, int left, int right) {
    if (right < start || end < left) {
        return INT_MAX;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, N, 1);
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        cout << query(1, N, 1, a, b) << '\n';
    }

    return 0;
}