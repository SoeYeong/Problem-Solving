// 확장 유클리드 호제법
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long t, K, C;
struct Result {
    long long s, t, r;
};
Result egcd(long long a, long long b) {
    long long s0 = 1, t0 = 0, r0 = a;
    long long s1 = 0, t1 = 1, r1 = b;

    long long temp;
    while (r1 != 0) {
        long long q = r0 / r1;

        temp = r0 - q * r1;
        r0 = r1;
        r1 = temp;

        temp = s0 - q * s1;
        s0 = s1;
        s1 = temp;

        temp = t0 - q * t1;
        t0 = t1;
        t1 = temp;
    }

    return { s0, t0, r0 };
}
void solve() {
    // K * X + 1 = C * Y
    // -K * X + C * Y = 1
    // K * (-X) + C * Y = 1

    // int D = gcd(A, B)
    // Ax + By = C 일 때, C % D == 0이어야 해를 가질 수 있다.

    Result result = egcd(K, C);
    if (result.r != 1) {
        // 해가 없음
        cout << "IMPOSSIBLE\n";
    }
    else {
        // 초기 해
        // x0 = s * C/D
        // y0 = t * C/D
        long long x0 = result.s;
        long long y0 = result.t;

        // 일반 해 공식 (k는 상수)
        // x = x0 + B/D * k
        // y = y0 - A/D * k

        // 해 범위
        // x < 0
        // x0 + B * k < 0 (D = 1)
        // k < -x0/B

        // 0 < y <= 10^9
        // 0 < y0 - A * k <= 10^9
        // (y0 - 10^9)/A <= k < y0/A
        long long kFromY = (long long)ceil((double)y0 / (double)K) - 1;
        long long kFromX = (long long)ceil((double)-x0 / (double)C) - 1;
        long long k = min(kFromX, kFromY);
        long long kLimitY = (long long)ceil((double)(y0 - 1e9) / (double)K);
        if (kLimitY <= k) {
            cout << y0 - K * k << '\n';
        }
        else {
            // 범위 만족하는 해 없음
            cout << "IMPOSSIBLE\n";
        }
    }
}
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> K >> C;
        solve();
    }

    return 0;
}