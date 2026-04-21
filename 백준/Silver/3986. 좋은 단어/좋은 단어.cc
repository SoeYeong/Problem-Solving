#include <iostream>
#include <stack>

using namespace std;

int n, ans;
string input;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> input;
        if (input.length() % 2 == 1) {
            continue;
        }
        stack <char> s;
        for (int i = 0; i < input.length(); i++) {
            if (s.empty()) {
                s.push(input[i]);
            }
            else {
                if (input[i] == s.top()) {
                    s.pop();
                }
                else {
                    s.push(input[i]);
                }
            }
        }
        
        if (s.empty()) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}