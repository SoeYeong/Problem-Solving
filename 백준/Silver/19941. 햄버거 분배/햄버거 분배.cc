#include <iostream>
#include <string>
using namespace std;

int N, K, cnt;
string str;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != 'P') continue;
        for (int j = i - K; j <= i + K; j++) {
            if (0 <= j && j < N && str[j] == 'H') {
                cnt++;
                str[j] = '.';
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}