#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B, x, y;

    cin >> N >> A >> B;
    for (int i = 0; i < 8 - N; i++) {
        cin >> x >> y;
        A += x * 3;
        B += x * 3;
        if (y <= 6 - x) {
            B += y * 3;
        }
        else {
            B += (6 - x) * 3;
        }
    }

    if (A >= 66 && B >= 130) {
        cout << "Nice";
    }
    else {
        cout << "Nae ga wae";
    }

    return 0;
}