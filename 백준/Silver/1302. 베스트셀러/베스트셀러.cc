#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, maxx;
string title;
map<string, int> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> title;
        m[title]++;
    }

    for (auto t : m) {
        if (t.second > maxx) {
            maxx = t.second;
            title = t.first;
        }
    }
    cout << title;

    return 0;
}