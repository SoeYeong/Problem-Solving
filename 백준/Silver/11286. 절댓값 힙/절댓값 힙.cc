#include <iostream>
#include <queue>
using namespace std;

struct num {
    int abs, real;
};
struct compare {
    bool operator()(num& a, num& b) {
        if (a.abs != b.abs) return a.abs > b.abs;
        else return a.real > b.real;
    }
};

int N, x;
priority_queue<num, vector<num>, compare> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int x;
    while (N--) {
        cin >> x;
        if (x) {
            if (x < 0) {
                pq.push({ -x, x });
            }
            else {
                pq.push({ x, x });
            }
        }
        else {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top().real << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}