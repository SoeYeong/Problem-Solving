#include <iostream>
using namespace std;

string hj;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> hj;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) cout << ":" << hj << ":";
            else cout << ":fan:";
        }
        cout << "\n";
    }

    return 0;
}