#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, X;
vector<int> arr;
int cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        arr.push_back(num);
    }
    cin >> X;
    sort(arr.begin(), arr.end());

    int left = 0, right = N - 1;
    while (left < right) {
        if (arr[left] + arr[right] == X) {
            cnt++;
            left++;
            right--;
        }
        else if (arr[left] + arr[right] > X) {
            right--;
        }
        else {
            left++;
        }
    }
    cout << cnt;

    return 0;
}