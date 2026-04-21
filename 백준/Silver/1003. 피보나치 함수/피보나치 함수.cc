#include <iostream>
#include <queue>
using namespace std;

int T, N;
long long cnt0[41], cnt1[41];
void fibonacci() {
    cnt0[0] = 1;
    cnt0[1] = 0;
    cnt1[0] = 0;
    cnt1[1] = 1;
    for (int i = 2; i < 41; i++) {
        cnt0[i] = cnt0[i - 1] + cnt0[i - 2];
        cnt1[i] = cnt1[i - 1] + cnt1[i - 2];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> T;
    fibonacci();
    while (T--) {
        cin >> N;
        cout << cnt0[N] << " " << cnt1[N] << "\n";
    }
	return 0;
}