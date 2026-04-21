#include <iostream>
using namespace std;

int L, P, V;
int cnt = 1;
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        cin >> L >> P >> V;
        if (!L && !P && !V) {
            break;
        }
        int q = V / P;
        int r = V % P;
        if (L < r) {
            r = L;
        }

        ans = L * q + r;
        cout << "Case " << cnt << ": " << ans << '\n';
        cnt++;
    }

    return 0;
}