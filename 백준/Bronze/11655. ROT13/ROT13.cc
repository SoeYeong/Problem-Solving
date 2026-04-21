#include <iostream>
#include <string>

using namespace std;

string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= 'A';
            s[i] += 13;
            s[i] %= 26;
            s[i] += 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 'a';
            s[i] += 13;
            s[i] %= 26;
            s[i] += 'a';
        }
    }
    cout << s;

    return 0;
}