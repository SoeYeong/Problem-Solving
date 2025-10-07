#include <iostream>
#include <algorithm>
using namespace std;

int K;
int cnt[2][46];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    cnt[0][0] = 1;
    for (int i = 1; i <= K; i++) {
        cnt[0][i] = cnt[1][i - 1];
        cnt[1][i] = cnt[0][i - 1] + cnt[1][i - 1];
    }

    cout << cnt[0][K] << " " << cnt[1][K];
    return 0;
}