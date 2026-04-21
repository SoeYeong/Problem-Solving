#include <iostream>
using namespace std;

int N;
int tree[27][2];
void pre(int node) {
    if (node == -1) return;
    cout << (char)(node + 'A');
    pre(tree[node][0]);
    pre(tree[node][1]);
}
void inorder(int node) {
    if (node == -1) return;
    inorder(tree[node][0]);
    cout << (char)(node + 'A');
    inorder(tree[node][1]);
}
void post(int node) {
    if (node == -1) return;
    post(tree[node][0]);
    post(tree[node][1]);
    cout << (char)(node + 'A');
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    char p, c1, c2;
    for (int i = 0; i < N; i++) {
        cin >> p >> c1 >> c2;
        if(c1 != '.')
            tree[p - 'A'][0] = c1 - 'A';
        else
            tree[p - 'A'][0] = -1;
        if (c2 != '.')
            tree[p - 'A'][1] = c2 - 'A';
        else
            tree[p - 'A'][1] = -1;
    }

    pre(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    post(0);

    return 0;
}