#include <iostream>

#define MAX 100001
using namespace std;

int N, Q;
long long num[MAX];
long long tree[4 * MAX];
void init(int start, int end, int node) {
    if (start == end) {
        tree[node] = num[start];
        return;
    }
    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(int start, int end, int node, int target, long long diff) {
    if (target < start || end < target) {
        return;
    }
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, target, diff);
        update(mid + 1, end, node * 2 + 1, target, diff);
    }
}
long long query(int start, int end, int node, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, N, 1);

    int x, y, a;
    long long b;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y >> a >> b;
        if (x < y) {
            cout << query(1, N, 1, x, y) << '\n';
        }
        else {
            cout << query(1, N, 1, y, x) << '\n';
        }
        update(1, N, 1, a, b - num[a]);
        num[a] = b;
    }

    return 0;
}