#include <iostream>
#define MAX 1025
using namespace std;

int N, M;
int x_1, y_1, x_2, y_2;
long long num[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> num[i][j];
            num[i][j] += num[i][j - 1];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            num[i][j] += num[i - 1][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        long long ans = num[x_2][y_2] - num[x_2][y_1 - 1] - num[x_1 - 1][y_2] + num[x_1 - 1][y_1 - 1];
        cout << ans << "\n";
    }

    return 0;
}