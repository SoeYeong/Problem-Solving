#include <iostream>
using namespace std;

int N, S, ans;
int arr[22];

void dfs(int idx, int val) {
    if (idx == N) {
        return;
    }
    if (val + arr[idx] == S) {
        ans++;
    }

    dfs(idx + 1, val);
    dfs(idx + 1, val + arr[idx]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);
    cout << ans;
    
    return 0;
}