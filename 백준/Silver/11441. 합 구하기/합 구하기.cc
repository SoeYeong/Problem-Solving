#include <iostream>

using namespace std;

int N, M;
int num[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        num[i] += num[i - 1];
    }

    cin >> M;
    int i, j;
    while (M--) {
        cin >> i >> j;
        cout << num[j] - num[i - 1] << '\n';
    }

    return 0;
}