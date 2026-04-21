#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, cnt;
int weight[101][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        weight[a][b] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (weight[i][k] && weight[k][j])
                    weight[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (weight[i][j] == 0 && weight[j][i] == 0) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}