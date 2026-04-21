#include <iostream>
#include <algorithm>

using namespace std;

int N;
int buildings[51];
int cnt[51];
void solve() {
    int ans = 0;

    for (int i = 1; i < N; i++) {
        double max_level = -9999999999;
        for (int j = i + 1; j <= N; j++) {
            double level = (double)(buildings[j] - buildings[i]) / (j - i);
            if (level > max_level) {
                cnt[i]++;
                cnt[j]++;
                max_level = level;
            }
        }
    }

    for (auto n : cnt) {
        ans = max(ans, n);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> buildings[i];
    }

    solve();

    return 0;
}