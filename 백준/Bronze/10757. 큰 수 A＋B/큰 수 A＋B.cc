#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b;
string sum(string a, string b) {
    int num = 0;
    int carry = 0;
    string result = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.length() < b.length()) {
        a += "0";
    }
    while (b.length() < a.length()) {
        b += "0";
    }

    for (int i = 0; i < a.length(); i++) {
        num = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
        result += to_string(num);
        carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
    }
    if (carry != 0) {
        result += to_string(carry);
    }

    reverse(result.begin(), result.end());
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    string ans = sum(a, b);
    cout << ans;
    return 0;
}