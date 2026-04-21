#include <iostream>
using namespace std;

int N, M;
int parent[100001];
long long weight[100001];
void init() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        weight[i] = 0;
    }
}
int findd(int a) {
    if (parent[a] == a) return a;

    int parentId = findd(parent[a]);
    weight[a] += weight[parent[a]];
    return parent[a] = parentId;
}
void unionn(int a, int b, int w) {
    int aRoot = findd(a);
    int bRoot = findd(b);
    if (aRoot > bRoot) {
        parent[aRoot] = bRoot;
        int temp = weight[b] - w;
        weight[aRoot] = temp - weight[a];
    }
    else {
        parent[bRoot] = aRoot;
        int temp = weight[a] + w;
        weight[bRoot] = temp - weight[b];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char cmd;
    int a, b, w;
    while (1) {
        cin >> N >> M;
        if (!N && !M) {
            break;
        }
        init();

        for (int i = 0; i < M; i++) {
            cin >> cmd;
            if (cmd == '!') {
                cin >> a >> b >> w;
                unionn(a, b, w);
            }
            else {
                cin >> a >> b;
                if (findd(a) != findd(b)) {
                    cout << "UNKNOWN\n";
                }
                else {
                    cout << weight[b] - weight[a] << '\n';
                }
            }
        }
    }

    return 0;
}