#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int idp[1001], ddp[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        idp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                idp[i] = max(idp[i], idp[j] + 1);
            }
        }
    }

    for (int i = N; i >= 1; i--) {
        ddp[i] = 1;
        for (int j = N; j > i; j--) {
            if (arr[j] < arr[i]) {
                ddp[i] = max(ddp[i], ddp[j] + 1);
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, idp[i] + ddp[i] - 1);
    }
    cout << ans;

    return 0;
}