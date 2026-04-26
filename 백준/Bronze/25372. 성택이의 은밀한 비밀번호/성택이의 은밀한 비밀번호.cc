#include <iostream>
#include <cstring>
using namespace std;

int N;
string pw;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pw;
        if (pw.length() >= 6 && pw.length() <= 9) cout << "yes\n";
        else cout << "no\n";
    }


    return 0;
}