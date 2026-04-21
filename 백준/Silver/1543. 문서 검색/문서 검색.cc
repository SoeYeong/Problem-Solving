#include <iostream>
#include <string>

using namespace std;

string s1, s2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s1);
    getline(cin, s2);
    int pos = 0, cnt = 0;

    while (s1.find(s2, pos) != string::npos) {
        pos = s1.find(s2, pos) + s2.length();
        cnt++;
    }
    cout << cnt;

    return 0;
}