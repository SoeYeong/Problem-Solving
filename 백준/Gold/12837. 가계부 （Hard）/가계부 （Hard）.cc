#include <iostream>

using namespace std;

int N, Q;
long long tree[2100000];
long long sum(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 0;
    }
    if (qLeft <= left && right <= qRight) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    return sum(left, mid, node * 2, qLeft, qRight) + sum(mid + 1, right, node * 2 + 1, qLeft, qRight);
}
void update(int left, int right, int node, int target, long long diff) {
    if (target < left || right < target) {
        return;
    }
    tree[node] += diff;
    if (left != right) {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid + 1, right, node * 2 + 1, target, diff);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;
    int cmd, p, q;
    for (int i = 1; i <= Q; i++) {
        cin >> cmd >> p >> q;
        if (cmd == 1) {
            update(1, N, 1, p, q);
        }
        else {
            cout << sum(1, N, 1, p, q) << '\n';
        }
    }

    return 0;
}