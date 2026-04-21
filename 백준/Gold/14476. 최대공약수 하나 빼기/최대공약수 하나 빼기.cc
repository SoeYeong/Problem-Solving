#include <iostream>
using namespace std;

int N;
int arr[1000001];
int gcdLtoR[1000001];
int gcdRtoL[1000001];
int maxx = 0, ans;
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    gcdLtoR[0] = arr[0];
    for (int i = 1; i < N; i++) {
        gcdLtoR[i] = gcd(arr[i], gcdLtoR[i - 1]);
    }

    gcdRtoL[N - 1] = arr[N - 1];
    for (int i = N - 1; i >= 0; i--) {
        gcdRtoL[i] = gcd(arr[i], gcdRtoL[i + 1]);
    }

    for (int i = 0; i < N; i++) {
        int temp = 0;
        if (i == 0) {
            temp = gcdRtoL[1];
        }
        else if (i == N - 1) {
            temp = gcdLtoR[N - 1];
        }
        else {
            temp = gcd(gcdLtoR[i - 1], gcdRtoL[i + 1]);
        }

        if (maxx < temp) {
            maxx = temp;
            ans = arr[i];
        }
    }

    if (maxx && ans % maxx) {
        cout << maxx << ' ' << ans;
    }
    else {
        cout << -1;
    }
    return 0;
}