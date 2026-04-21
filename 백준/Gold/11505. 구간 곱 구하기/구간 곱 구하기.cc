#include <iostream>

#define MAX 1000001
#define MOD 1000000007
using namespace std;

int N, M, K;
long long arr[MAX];
long long tree[MAX * 4];

long long query(int left, int right, int node, int qLeft, int qRight) {
    if (left > qRight || right < qLeft) {
        return 1;
    }
    if (qLeft <= left && right <= qRight) {
        return tree[node];
    }

    int mid = (left + right) / 2;
    return (query(left, mid, node * 2, qLeft, qRight) * query(mid + 1, right, node * 2 + 1, qLeft, qRight)) % MOD;
}
void update(int left, int right, int node, int idx, long long value) {
    if (idx < left || idx > right) {
        return;
    }

    if (left == right) {
        tree[node] = value;
        return;
    }

    int mid = (left + right) / 2;
    update(left, mid, node * 2, idx, value);
    update(mid + 1, right, node * 2 + 1, idx, value);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}
long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, 1, N);

    int a, b;
    long long c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, N, 1, b, c);
        }
        else {
            cout << query(1, N, 1, b, c) << "\n";
        }
    }

    return 0;
}