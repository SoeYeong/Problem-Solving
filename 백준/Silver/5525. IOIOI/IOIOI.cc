#include <iostream>
using namespace std;

int N, M, ans;
string S;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> S;

    for (int i = 0; i < M; i++) {
        if (S[i] == 'O') continue;
        
        int cnt = 0;
        while (S[i + 1] == 'O' && S[i + 2] == 'I') {
            cnt++;
            if (cnt == N) {
                ans++;
                cnt--;
            }
            i += 2;
        }
    }


    cout << ans;
    return 0;
}