#include <iostream>
using namespace std;

int N, T, P;
int tshirts[6];
int total, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> tshirts[i];
        total += tshirts[i];
    }
    cin >> T >> P;

    for (int i = 0; i < 6; i++) {
        if (tshirts[i] == 0) continue;
        ans += (tshirts[i] - 1) / T + 1;
    }
    cout << ans << "\n";
    cout << total / P << " " << total % P;
    
    return 0;
}