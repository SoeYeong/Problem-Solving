// 최단 경로 : 플로이드-워셜
#include <iostream>
#include <algorithm>
#define MAX 101
#define INF 0x7fffffff
using namespace std;

int N, M;
int from, to, cost;
int city[MAX][MAX];
void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) city[i][j] = 0;
            else city[i][j] = INF;
        }
    }
}
void find() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (city[i][k] == INF) continue;
                if (city[k][j] == INF) continue;
                if (city[i][j] > city[i][k] + city[k][j]) {
                    city[i][j] = city[i][k] + city[k][j];
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    init();
    while (M--) {
        cin >> from >> to >> cost;
        city[from][to] = min(city[from][to], cost);
    }
    find();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (city[i][j] == INF) city[i][j] = 0;
            cout << city[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}