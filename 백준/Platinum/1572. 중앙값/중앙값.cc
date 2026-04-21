#include <iostream>
#include <queue>

#define MAX 65536
using namespace std;

int N, K;
int arr[250001];
int tree[MAX * 4 + 1];
long long ans;
void update(int left, int right, int node, int target, int diff) {
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
int find(int left, int right, int node, int ranking) {
    if (left == right) return left;
    int mid = (left + right) / 2;
    if (tree[node * 2] >= ranking) {
        return find(left, mid, node * 2, ranking);
    }
    else {
        return find(mid + 1, right, node * 2 + 1, ranking - tree[node * 2]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    queue<int> q;
    for (int i = 1; i <= K; i++) {
        update(0, MAX, 1, arr[i], 1);
        q.push(arr[i]);
    }
    ans += (long long)find(0, MAX, 1, (K + 1) / 2);
    for (int i = K + 1; i <= N; i++) {
        update(0, MAX, 1, q.front(), -1);
        q.pop();
        update(0, MAX, 1, arr[i], 1);
        q.push(arr[i]);
        ans += (long long)find(0, MAX, 1, (K + 1) / 2);
    }

    cout << ans;
    return 0;
}