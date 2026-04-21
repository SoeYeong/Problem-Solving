#include <iostream>
using namespace std;

int a, b, c, d;
int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cin >> c >> d;

    int e = a * d + c * b;
    int f = b * d;
    int gcd = get_gcd(e, f);
    e /= gcd;
    f /= gcd;

    cout << e << ' ' << f;

    return 0;
}