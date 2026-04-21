#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    char result[5] = { 'E', 'A', 'B', 'C', 'D'};
    int a, b, c, d, sum;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b >> c >> d;
        sum = a + b + c + d;
        cout << result[4-sum] << "\n";
    }

    return 0;
}