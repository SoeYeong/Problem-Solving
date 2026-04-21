#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr, ans;

int binary_search(int x) {
    int low = 0;
    int high = ans.size() - 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;

        if (ans[mid] >= x) {
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

    ans.push_back(arr.front());
    for (int i = 1; i < N; i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        }
        else {
            idx = binary_search(arr[i]);
            ans[idx] = arr[i];
        }
    }
    cout << ans.size();

    return 0;
}