#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    int low = 1;
    int high = K;
    while (low < high) {
        int mid = (low + high) / 2;
        int cnt = 0;

        for (int i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }

        if (cnt < K) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    cout << high;
    
    return 0;
}