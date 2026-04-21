#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num[9];
bool visit[9];
vector<int> v;
bool flag;
void dfs(int idx, int level, int sum) {
    if (flag) return;
    if (level == 7) {
        if (sum == 100) {
            flag = true;
            sort(v.begin(), v.end());
            for (int i = 0; i < 7; i++) {
                cout << v[i] << "\n";
            }
            return;
        }
        return;
    }

    for (int i = idx; i < 9; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        v.push_back(num[i]);
        dfs(i + 1, level + 1, sum + num[i]);
        visit[i] = false;
        v.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        cin >> num[i];
    }
    dfs(0, 0, 0);

    return 0;
}