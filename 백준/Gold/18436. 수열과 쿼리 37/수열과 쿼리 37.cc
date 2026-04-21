#include <iostream>

#define MAX 100001
using namespace std;

int N, M;
int arr[MAX];
int tree[MAX * 4];  // 홀수 개수

int query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 0;
    }

    if (qLeft <= left && right <= qRight) {
        return tree[node];
    }

    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 + 1, qLeft, qRight);
}
void update(int left, int right, int node, int index, int val) {
    if (index < left || right < index) return;

    if (val % 2 == 0) {
        tree[node]--;
    }
    else {
        tree[node]++;
    }

    if (left == right) {
        //tree[node] = val % 2 ? 1 : 0;
        return;
    }

    int mid = (left + right) / 2;
    update(left, mid, node * 2, index, val);
    update(mid + 1, right, node * 2 + 1, index, val);
}
int init(int node, int start, int end) {
    if (start == end) {
        if (arr[start] % 2) {
            return tree[node] = 1;
        }
        else {
            return tree[node] = 0;
        }
    }

    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, 1, N);

    int a, b, c;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            // 홀수 -> 짝수
            if ((arr[b] % 2) && (c % 2 == 0)) update(1, N, 1, b, c);
            // 짝수 -> 홀수
            else if ((arr[b] % 2 == 0) && (c % 2)) update(1, N, 1, b, c);
            arr[b] = c;
        }
        else if (a == 2) {
            int num = query(1, N, 1, b, c);
            cout << (c - b - num + 1) << "\n";
        }
        else {
            cout << query(1, N, 1, b, c) << "\n";
        }
    }

    return 0;
}