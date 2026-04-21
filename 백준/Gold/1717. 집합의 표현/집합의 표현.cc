#include <iostream>
using namespace std;

int n, m;
int parent[1000001];
void init() {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}
int findd(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = findd(parent[a]);
}
void unionn(int a, int b) {
    int aRoot = findd(a);
    int bRoot = findd(b);
    parent[aRoot] = bRoot;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int cmd, a, b;
    init();

    for (int i = 0; i < m; i++) {
        cin >> cmd >> a >> b;
        if (cmd) {
            if (findd(a) == findd(b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            unionn(a, b);
        }
    }

    return 0;
}