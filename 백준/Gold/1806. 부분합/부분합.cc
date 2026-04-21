#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int arr[100001];
int low = 1, high = 1;
int len = 0x7fffffff;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    while (high <= N) {
        long long sum = arr[high] - arr[low - 1];
        if (sum > S) {
            len = min(len, high - low + 1);
            low++;
        }
        else if (sum < S) {
            high++;
        }
        else {
            len = min(len, high - low + 1);
            high++;
        }
    }

    if (len == 0x7fffffff) {
        len = 0;
    }
    cout << len;
    return 0;
}