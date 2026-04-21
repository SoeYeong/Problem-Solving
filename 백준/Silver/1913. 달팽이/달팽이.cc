#include <iostream>
#include <vector>

#define MAX 1000
using namespace std;

int arr[MAX][MAX];
int N, M, r, c;
vector <int> v;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int rr, cc;
    rr = cc = (N + 1) / 2;

    for (int i = 1; i < N; i++) {
        v.push_back(i);
        v.push_back(i);
    }
    v.push_back(N - 1);

    int num = 1;
    arr[rr][cc] = num;
    num++;
    int d = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i]; j++) {
            rr += dr[d];
            cc += dc[d];
            arr[rr][cc] = num;
            num++;
        }
        d++;
        d %= 4;
    }

    // print
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
            if (arr[i][j] == M) {
                r = i, c = j;
            }
        }
        cout << "\n";
    }
    cout << r << " " << c;

    return 0;
}