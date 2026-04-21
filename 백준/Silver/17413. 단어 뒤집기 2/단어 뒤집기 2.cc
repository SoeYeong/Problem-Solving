#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s, result, word;
bool tag = false;
stack<char> st;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s);
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size()) {
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
        }
        else if (tag) {
            result += s[i];
            if (s[i] == '>') {
                tag = false;
            }
        }
        else if (s[i] == '<') {
            tag = true;
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            result += s[i];
        }
        else if (s[i] == ' ') {
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            result += s[i];
        }
        else {
            st.push(s[i]);
        }
    }

    cout << result;

    return 0;
}