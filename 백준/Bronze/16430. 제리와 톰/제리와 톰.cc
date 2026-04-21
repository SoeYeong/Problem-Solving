#include <iostream>
using namespace std;

int A, B;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B;
    int P = B - A;
    int Q = B;
    for (int i = B - A; i > 0; i--) {
        if (P % i == 0 && Q % i == 0) {
            P /= i;
            Q /= i;
        }
    }

    cout << P << ' ' << Q;
    return 0;
}