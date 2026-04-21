#include <iostream>

using namespace std;

int N;
int A[500001];
int B[1000001];
int tree[2100000];
long long ans;
long long query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 0;
    }
    if (qLeft <= left && right <= qRight) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 + 1, qLeft, qRight);
}
void update(int left, int right, int node, int target) {
    if (target < left || target > right) {
        return;
    }
    tree[node] += 1;
    if (left != right) {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target);
        update(mid + 1, right, node * 2 + 1, target);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int num;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        B[num] = i;
    }

    for (int i = 1; i <= N; i++) {
        ans += query(1, N, 1, B[A[i]] + 1, N);
        update(1, N, 1, B[A[i]]);
    }

    cout << ans;
    return 0;
}