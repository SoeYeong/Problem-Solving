#include <iostream>
using namespace std;

string code, input;
int n, alph[26], num[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> code;
    for (int i = 0; i < code.length(); i++) {
        if (code[i] >= 'A')
            alph[code[i] - 'A']++;
        else
            num[code[i] - '0']++;
    }

    cin >> n;
    while (n--) {
        cin >> input;

        int a = 0, b = 0;
        for (int i = 0; i < code.length(); i++) {
            if (code[i] == input[i]) {
                a++;
            }
            else if (input[i] >='A') {
                if(alph[input[i]-'A'])
                    b++;
            }
            else if (input[i] >= '0') {
                if (num[input[i] - '0'])
                    b++;
            }
        }
        cout << a << " " << b << "\n";
    }

    return 0;
}