#include <iostream>
#include <algorithm>
using namespace std;

int N;
int minn[3], maxx[3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> minn[0] >> minn[1] >> minn[2];
    maxx[0] = minn[0], maxx[1] = minn[1], maxx[2] = minn[2];

    int a, b, c;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;

        int temp1 = maxx[0], temp2 = maxx[2];
        maxx[0] = max(maxx[0], maxx[1]) + a;
        maxx[2] = max(maxx[1], maxx[2]) + c;
        maxx[1] = max(temp1, max(maxx[1], temp2)) + b;

        temp1 = minn[0], temp2 = minn[2];
        minn[0] = min(minn[0], minn[1]) + a;
        minn[2] = min(minn[1], minn[2]) + c;
        minn[1] = min(temp1, min(minn[1], temp2)) + b;
    }

    cout << max(maxx[0], max(maxx[1], maxx[2])) << ' ';
    cout << min(minn[0], min(minn[1], minn[2]));
    return 0;
}