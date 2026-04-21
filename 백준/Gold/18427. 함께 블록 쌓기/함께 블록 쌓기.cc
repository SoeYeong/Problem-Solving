#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define NMAX 51
#define HMAX 1001
#define MOD 10007
using namespace std;

int N, M, H;
string temp;
vector<int> v[NMAX];
int dp[NMAX][HMAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> H;
    cin.ignore();
    for (int i = 1; i <= N; i++) {
        getline(cin, temp);
        stringstream sstr(temp);
        int num;
        while (sstr >> num) {
            v[i].push_back(num);
        }
    }

    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= H; j++) {
            for (int k = 0; k < v[i].size(); k++) {
                if (v[i][k] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i][k]]) % MOD;
                }
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }

    cout << dp[N][H];
    return 0;
}