#include <iostream>
using namespace std;

int N, M, K;
long long nums[1000001];
long long tree[2100000];
int S = 1;
// Bottom-up initialize
void init() {
    while (S < N) {
        S *= 2;
    }

    for (int i = 0; i < N; i++) {
        tree[S + i] = nums[i];
    }
    for (int i = S - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}
// Top-down query
long long query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 0;
    }
    else if (qLeft <= left && right <= qRight) {
        return tree[node];
    }
    else {
        int mid = (left + right) / 2;
        return query(left, mid, node * 2, qLeft, qRight)
                + query(mid+1, right, node * 2 + 1, qLeft, qRight);
    }
}
// Top-down update
void update(int left, int right, int node, int target, long long diff) {
    if (target < left || right < target) {
        return;
    }
    else {
        tree[node] += diff;
        if (left != right) {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, target, diff);
            update(mid + 1, right, node * 2 + 1, target, diff);
        }
    }
}
// Bottom-up query
long long queryBU(int qLeft, int qRight) {
    int leftNode = S + qLeft - 1;
    int rightNode = S + qRight - 1;
    long long sum = 0;
    while (leftNode <= rightNode) {
        if (leftNode % 2 == 1) {
            sum += tree[leftNode++];
        }
        else if (rightNode % 2 == 0 ) {
            sum += tree[rightNode--];
        }
        leftNode /= 2;
        rightNode /= 2;
    }
    return sum;
}
// Bottom-up update
void updateBU(int target, long long value) {
    int node = S + target - 1;
    tree[node] = value;
    node /= 2;
    while (node > 0) {
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
        node /= 2;
    }
}
int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    init();

    int a, b;
    long long c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        // update
        if (a == 1) {
            update(1, S, 1, b, c - tree[S + b - 1]);
            //updateBU(b, c);
        }
        // query
        else {
            cout << query(1, S, 1, b, c) << '\n';
            //cout << queryBU(b, c) << '\n';
        }
    }

    return 0;
}