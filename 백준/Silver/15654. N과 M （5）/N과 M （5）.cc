#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
bool visit[10];
int num[10];
void dfs(int n) {
    if (n == M) {
        for (int i = 0; i < M; i++) {
            cout << num[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        num[n] = arr[i];
        dfs(n + 1);
        visit[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    dfs(0);

    return 0;
}