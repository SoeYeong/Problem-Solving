#include <iostream>
using namespace std;

int N, cnt = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int pos1 = 1, pos2 = 1, sum = 1;

    while (pos2 != N) {
        if (sum == N) {
            cnt++;
            pos2++;
            sum += pos2;
        }
        else if (sum > N) {
            sum -= pos1;
            pos1++;
        }
        else {
            pos2++;
            sum += pos2;
        }
    }

    cout << cnt;
    return 0;
}