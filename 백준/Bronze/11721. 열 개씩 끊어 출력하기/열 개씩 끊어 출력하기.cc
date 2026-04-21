#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
        cnt++;
        if (cnt == 10) {
            cout << "\n";
            cnt = 0;
        }
    }

    return 0;
}