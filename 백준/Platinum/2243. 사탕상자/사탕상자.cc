// Indexed tree
// index: 사탕의 맛, value: 사탕의 개수
#include <iostream>
using namespace std;

int N;
int a, b, c;
int tree[2100000];
int S = 1;
int result;
void init() {
    while (S <= 1000000) {
        S *= 2;
    }
}
int query(int left, int right, int node, int target) {
    // leaf node에 도달한 경우
    if (left == right) {
        return left;
    }

    int mid = (left + right) / 2;
    if (tree[node * 2] >= target) {
        return query(left, mid, node * 2, target);
    }
    else {
        return query(mid + 1, right, node * 2 + 1, target - tree[node * 2]);
    }
}
void update(int left, int right, int node, int target, int diff) {
    if (target < left || target > right) {
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
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    init();
    for (int i = 0; i < N; i++) {
        cin >> a;
        // 사탕 꺼내기
        if (a == 1) {
            cin >> b;
            result = query(1, S, 1, b);
            update(1, S, 1, result, -1);
            cout << result << '\n';
        }
        // 사탕 넣기
        else {
            cin >> b >> c;
            update(1, S, 1, b, c);
        }
    }

    return 0;
}