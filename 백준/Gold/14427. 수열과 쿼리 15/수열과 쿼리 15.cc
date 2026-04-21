#include <iostream>

#define MAX 100001
using namespace std;

int N, M;
int arr[MAX];
int tree[MAX * 4];
int minIdx(int x, int y) {
    if (arr[x] == arr[y]) return x < y ? x : y;
    return arr[x] < arr[y] ? x : y;
}
int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = start;
    }

    int mid = (start + end) / 2;
    return tree[node] = minIdx(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
void update(int start, int end, int node, int target) {
    if (target < start || end < target) {
        return;
    }
    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, target);
    update(mid + 1, end, node * 2 + 1, target);
    tree[node] = minIdx(tree[node * 2], tree[node * 2 + 1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, N, 1);

    int cmd, i, v;
    cin >> M;
    while (M--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> i >> v;
            arr[i] = v;
            update(1, N, 1, i);
        }
        else {
            cout << tree[1] << "\n";
        }
    }

    return 0;
}