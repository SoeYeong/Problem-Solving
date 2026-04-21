#include <iostream>
#include <algorithm>

#define MAX 100001
using namespace std;

int N, M;
int x[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x[i];
    }

    int answer = 1;
    for (int i = 0; i < M; i++) {
        if (i == 0) {
            answer = max(answer, x[i]);
        }
        else {
            answer = max(answer, (x[i] - x[i - 1] + 1) / 2);
        }

        if (i == M - 1) {
            answer = max(answer, N - x[i]);
        }
    }

    cout << answer;
    return 0;
}