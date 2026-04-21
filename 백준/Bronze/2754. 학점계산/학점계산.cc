#include <iostream>
#include <string>
using namespace std;

string score;
float ans;
float grade[4] = { 4,3,2,1 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> score;

    if (score[0] == 'F') {
        ans = 0;
    }
    else {
        ans = grade[score[0] - 'A'];
        if (score[1] == '+')
            ans += 0.3;
        else if (score[1] == '-')
            ans -= 0.3;
    }

    cout << fixed;
    cout.precision(1);
    cout << ans;
    return 0;
}