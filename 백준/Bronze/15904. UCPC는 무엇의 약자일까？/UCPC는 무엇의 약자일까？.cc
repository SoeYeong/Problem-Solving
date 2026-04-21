#include <iostream>
#include <string>
using namespace std;

string input;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getline(cin, input);

    int n1, n2, n3, n4;
    n1 = input.find('U');
    n2 = input.find('C', n1);
    n3 = input.find('P', n2);
    n4 = input.find('C', n3);

    if (n1 == -1 || n2 == -1 || n3 == -1 || n4 == -1) {
        cout << "I hate UCPC";
    }
    else {
        cout << "I love UCPC";
    }
    return 0;
}