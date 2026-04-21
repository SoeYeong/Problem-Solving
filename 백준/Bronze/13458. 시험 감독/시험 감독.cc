#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> Ai;
int B, C;
long long total;

void cal(int a) {
    total += 1;
    int r = a - B;
    if (r <= 0) return;

    if (r % C == 0) {
        int rr = r / C;
        total += rr;
    }
    else {
        int rr = r / C + 1;
        total += rr;
    }

}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        Ai.push_back(a);
    }
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        cal(Ai[i]);
    }
    cout << total;
    return 0;
}