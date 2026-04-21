#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0xffff
using namespace std;

int N;
int a, b;
int friends[51][51];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j || friends[i][j]) continue;
            friends[i][j] = INF;
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
            }
        }
    }

    int score = INF;
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        int maxx = 0;
        for (int j = 1; j <= N; j++) {
            if (maxx < friends[i][j]) {
                maxx = friends[i][j];
            }
        }

        if (score > maxx) {
            score = maxx;
            cnt = 0;
            v.clear();
        }
        if (score == maxx) {
            cnt++;
            v.push_back(i);
        }
    }

    cout << score << " " << cnt << "\n";
    for (auto n : v) {
        cout << n << " ";
    }

    return 0;
}