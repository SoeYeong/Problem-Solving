#include <iostream>
#include <string>

using namespace std;

int M;
int s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M;

    string cmd;
    int x;
    while (M--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            s |= (1 << x);
        }
        else if (cmd == "remove") {
            cin >> x;
            s &= ~(1 << x);
        }
        else if (cmd == "check") {
            cin >> x;
            int temp = s;
            cout << (1 & (temp >> x)) << '\n';
        }
        else if (cmd == "toggle") {
            cin >> x;
            s ^= (1 << x);
        }
        else if (cmd == "all") {
            s = 0x7fffffff;
        }
        else {
            s = 0;
        }
    }

    return 0;
}