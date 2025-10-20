#include <iostream>
#include <string>
using namespace std;

int N, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i < 100) {
            ans++;
        }
        else {
            string s = to_string(i);
            int d = (s[0] - '0') - (s[1] - '0');
            bool flag = true;
            for (int j = 2; j < s.length(); j++) {
                if (d != (s[j - 1] - '0') - (s[j] - '0')) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}