#include <iostream>
#include <vector>
using namespace std;

int N, cnt;
vector<int> arr, v, ans;
int dp[1000001];

int binary_search(int x) {
    int low = 0;
    int high = v.size() - 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;

        if (v[mid] >= x) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return high;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, idx;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        arr.push_back(x);
    }

    v.push_back(arr.front());
    for (int i = 1; i < N; i++) {
        if (arr[i] > v.back()) {
            v.push_back(arr[i]);
            cnt++;
            dp[i] = cnt;
        }
        else {
            idx = binary_search(arr[i]);
            v[idx] = arr[i];
            dp[i] = idx;
        }
    }
    cout << v.size() << "\n";

    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] == cnt) {
            ans.push_back(arr[i]);
            cnt--;
        }
        if (cnt == -1) {
            break;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}