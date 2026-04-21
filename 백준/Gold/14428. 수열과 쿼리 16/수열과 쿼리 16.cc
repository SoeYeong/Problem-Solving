#include <iostream>
using namespace std;

int N, M;
int num[100001];
int tree[400000];
int minIdx(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    if (num[x] == num[y]) return x < y ? x : y;
    return num[x] <= num[y] ? x : y;
}
int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = start;
    }
    int mid = (start + end) / 2;
    return tree[node] = minIdx(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
int update(int start, int end, int node, int target) {
    if (target < start || end < target) {
        return tree[node];
    }
    if (start == end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = minIdx(update(start, mid, node * 2, target),
        update(mid + 1, end, node * 2 + 1, target));
}
int query(int start, int end, int node, int left, int right) {
    if (right < start || end < left) {
        return -1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return minIdx(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, N, 1);

    cin >> M;
    int cmd, i, j;
    while (M--) {
        cin >> cmd >> i >> j;
        if (cmd == 1) {
            num[i] = j;
            update(1, N, 1, i);
        }
        else {
            cout << query(1, N, 1, i, j) << '\n';
        }
    }

    return 0;
}