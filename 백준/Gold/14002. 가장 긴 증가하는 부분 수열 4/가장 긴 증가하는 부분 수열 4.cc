// DP : 가장 긴 증가하는 부분 수열(LIS)
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001
using namespace std;

int N;
int arr[MAX], dp[MAX];
int len;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                len = max(len, dp[i]);
            }
        }
    }

    cout << len << '\n';
    vector<int> v;
    for (int i = N; i > 0; i--) {
        if (dp[i] == len) {
            v.push_back(arr[i]);
            len--;
        }
        if (len == 0) {
            break;
        }
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }

    return 0;
}