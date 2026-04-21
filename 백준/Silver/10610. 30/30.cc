#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string N;
int sum;
bool zero = false;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N.length(); i++) {
        sum += N[i] - '0';
        if (N[i] == '0') {
            zero = true;
        }
    }

    if (zero && (sum % 3 == 0)) {
        sort(N.begin(), N.end(), greater<>());
        cout << N;
    }
    else {
        cout << -1;
    }

    return 0;
}