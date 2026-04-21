#include <iostream>
#include <stack>

using namespace std;

string input;
stack <char> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    int total = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            s.push(input[i]);
        }
        else if (input[i] == ')' && input[i - 1] == '(') {
            s.pop();
            total += s.size();
        }
        else {
            total++;
            s.pop();
        }
    }

    cout << total;

    return 0;
}