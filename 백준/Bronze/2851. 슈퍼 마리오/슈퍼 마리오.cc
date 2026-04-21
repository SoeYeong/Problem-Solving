#include <iostream>
#include <cmath>

using namespace std;

int num[11];
int sum, ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 10; i++) {
        sum += num[i];
        if (abs(100 - sum) <= abs(100 - ans)) {
            ans = sum;
        }
    }
    cout << ans;

    return 0;
}