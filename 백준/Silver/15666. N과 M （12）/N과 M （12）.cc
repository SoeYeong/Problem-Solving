#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
int num[10];
void dfs(int n, int idx) {
    if (n == M) {
        for (int i = 0; i < M; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        num[n] = arr[i];
        dfs(n + 1, i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    dfs(0, 0);
    return 0;
}