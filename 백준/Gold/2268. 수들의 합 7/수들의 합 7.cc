#include <iostream>

using namespace std;

int N, M;
int A[1000001];
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
void modify(int left, int right, int node, int target, long long diff) {
    if (target < left || target > right) {
        return;
    }
    tree[node] += diff;
    if (left != right) {
        int mid = (left + right) / 2;
        modify(left, mid, node * 2, target, diff);
        modify(mid + 1, right, node * 2 + 1, target, diff);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int cmd, i, j;
    for (int k = 0; k < M; k++) {
        cin >> cmd >> i >> j;
        if (cmd == 0) {
            if (i < j) {
                cout << sum(1, N, 1, i, j) << '\n';
            }
            else {
                cout << sum(1, N, 1, j, i) << '\n';
            }
        }
        else {
            long long diff = j - A[i];
            A[i] = j;
            modify(1, N, 1, i, diff);
        }
    }

    return 0;
}