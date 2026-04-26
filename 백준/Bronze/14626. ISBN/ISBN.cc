#include <iostream>
using namespace std;

string isbn;
int num[13];
int mod_3[10] = { 0,7,4,1,8,5,2,9,6,3 };
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> isbn;
    for (int i = 0; i < 13; i++) {
        if (isbn[i] == '*')
            n = i;
        else
            num[i] = isbn[i] - '0';
    }

    int sum = 0;
    for (int i = 0; i < 13; i++) {
        if (i % 2 == 0) {
            sum += num[i];
        }
        else {
            sum += 3 * num[i];
        }
    }

    num[n] = (10 - (sum % 10)) % 10;
    if (n % 2 == 1) {
        num[n] = mod_3[num[n]];
    }

    cout << num[n];
    return 0;
}