#include <iostream>

using namespace std;

int N, M, K;
int num[301][301];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> num[i][j];
            num[i][j] += num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1];
        }
    }

    cin >> K;
    int i, j, x, y;
    while (K--) {
        cin >> i >> j >> x >> y;
        int sum = num[x][y] - num[i - 1][y] - num[x][j - 1] + num[i - 1][j - 1];
        cout << sum << '\n';
    }

    return 0;
}