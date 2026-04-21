#include <iostream>
#include <algorithm>

#define MAX 50001
#define INF 1000001
using namespace std;

int N, Q;
int cow[MAX];
int min_tree[MAX * 4];
int max_tree[MAX * 4];

void init(int start, int end, int node) {
    if (start == end) {
        min_tree[node] = cow[start];
        max_tree[node] = cow[start];
        return;
    }

    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}
int find_min(int start, int end, int node, int left, int right) {
    if (end < left || right < start) {
        return INF;
    }
    if (left <= start && end <= right) {
        return min_tree[node];
    }

    int mid = (start + end) / 2;
    return min(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}
int find_max(int start, int end, int node, int left, int right) {
    if (end < left || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return max_tree[node];
    }
    int mid = (start + end) / 2;
    return max(find_max(start, mid, node * 2, left, right), find_max(mid + 1, end, node * 2 + 1, left, right));

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> cow[i];
    }
    init(1, N, 1);

    int a, b;
    while (Q--) {
        cin >> a >> b;
        int m = find_min(1, N, 1, a, b);
        int M = find_max(1, N, 1, a, b);
        cout << M - m << "\n";
    }

    return 0;
}