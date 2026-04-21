#include <iostream>
using namespace std;

int N, M, K;
long long num[1000001];
long long lazy[2100000];
long long tree[2100000];

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
void update_lazy(int start, int end, int node) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int start, int end, int node, int left, int right, long long val) {
    update_lazy(start, end, node);
    if (right < start || end < left) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(start, mid, node * 2, left, right, val);
    update_range(mid + 1, end, node * 2 + 1, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
long long sum(int start, int end, int node, int left, int right) {
    update_lazy(start, end, node);
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, N, 1);

    int a, b, c;
    long long d;
    for (int i = 1; i <= M + K; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update_range(1, N, 1, b, c, d);
        }
        else {
            cin >> b >> c;
            cout << sum(1, N, 1, b, c) << '\n';
        }
    }

    return 0;
}