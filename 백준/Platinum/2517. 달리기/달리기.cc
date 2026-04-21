#include <iostream>
#include <algorithm>

#define MAX 500001
using namespace std;

struct Data {
    int ability, idx;
};

int N;
Data runner[MAX];
int tree[MAX * 4];
bool cmp1(Data& a, Data& b) {
    return a.ability < b.ability;
}
bool cmp2(Data& a, Data& b) {
    return a.idx < b.idx;
}
void update(int left, int right, int node, int target, int diff) {
    if (target < left || right < target) return;
    tree[node] += diff;
    if (left != right) {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid + 1, right, node * 2 + 1, target, diff);
    }
}
int find(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 0;
    }
    if (qLeft <= left && right <= qRight) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    return find(left, mid, node * 2, qLeft, qRight) + find(mid + 1, right, node * 2 + 1, qLeft, qRight);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> runner[i].ability;
        runner[i].idx = i;
    }

    sort(runner, runner + N, cmp1);
    for (int i = 0; i < N; i++) {
        runner[i].ability = i + 1;
    }
    sort(runner, runner + N, cmp2);

    for (int i = 1; i <= N; i++) {
        update(1, N, 1, runner[i - 1].ability, 1);
        cout << i - find(1, N, 1, 1, runner[i - 1].ability - 1);
        cout << '\n';
    }

    return 0;
}