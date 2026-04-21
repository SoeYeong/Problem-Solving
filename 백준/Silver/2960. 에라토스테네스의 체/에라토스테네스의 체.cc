#include <iostream>
using namespace std;

int N, K;
int cnt = 1;
int nums[1001];
void delete_num() {
    for (int i = 2; i <= N; i++) {
        if (nums[i]) continue;
        for (int j = 1; i*j <= N; j++) {
            if (nums[i*j]) continue;
            nums[i*j] = cnt;
            if (cnt == K) {
                cout << i * j;
            }
            cnt++;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    delete_num();

    return 0;
}