#include <iostream>
#include <string>
using namespace std;

string str[3];
string fzbz[3] = { "FizzBuzz", "Fizz", "Buzz" };
void output(int x) {
    if (x % 15 == 0) {
        cout << fzbz[0];
    }
    else if (x % 3 == 0) {
        cout << fzbz[1];
    }
    else if (x % 5 == 0) {
        cout << fzbz[2];
    }
    else {
        cout << x;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str[0] >> str[1] >> str[2];

    int x = 0;
    if (str[2][0] >= '0' && str[2][0] <= '9') {
        x = stoi(str[2]) + 1;
    }
    else if (str[1][0] >= '0' && str[1][0] <= '9') {
        x = stoi(str[1]) + 2;
    }
    else if (str[0][0] >= '0' && str[0][0] <= '9') {
        x = stoi(str[0]) + 3;
    }
    output(x);
    
    return 0;
}