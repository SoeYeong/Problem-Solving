#include <iostream>
#include <string>
using namespace std;

string A, B, C;
int ans1, ans2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;

    ans1 = stoi(A) + stoi(B) - stoi(C);
    ans2 = stoi(A + B) - stoi(C);
    cout << ans1 << "\n" << ans2;
    
    return 0;
}