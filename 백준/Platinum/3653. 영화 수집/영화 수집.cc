#include <iostream>

using namespace std;

int T, n, m;
int arr[100001];
int tree[600000];
int leaf = 1;
void update(int left, int right, int node, int target, int diff) {
    if (target < left || right < target) return;

    tree[node] += diff;
    if (left != right) {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid + 1, right, node * 2 + 1, target, diff);
    }
}
int query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 0;
    }
    if (qLeft <= left && right <= qRight) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 + 1, qLeft, qRight);
}
void init() {
    while (leaf < n + m) {
        leaf *= 2;
    }
    for (int i = leaf; i < leaf + n; i++) {
        tree[i] = 1;
    }
    for (int i = leaf + n; i < 2 * leaf; i++) {
        tree[i] = 0;
    }
    for (int i = leaf - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = n - i + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();

        int size = n + m;
        int num;
        for (int i = 0; i < m; i++) {
            cin >> num;
            int target = arr[num];
            cout << query(1, leaf, 1, target + 1, size) << ' ';
            update(1, leaf, 1, target, -1);
            update(1, leaf, 1, n + 1, 1);
            arr[num] = ++n;
        }
        cout << '\n';
    }

    return 0;
}