#include <iostream>
using namespace std;

int N, ans;
int score[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    for (int i = N; i > 1; i--) {
        if (score[i] <= score[i - 1]) {
            ans += score[i - 1] - (score[i] - 1);
            score[i - 1] = score[i] - 1;
        }
    }
    cout << ans;
    return 0;
}