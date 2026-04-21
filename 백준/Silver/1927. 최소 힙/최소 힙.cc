#include <iostream>
#include <queue>
using namespace std;

int N, x;
struct compare {
    bool operator()(int &a, int &b) {
        return a > b;
    }
};
priority_queue<int, vector<int>, compare> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x) {
            pq.push(x);
        }
        else {
            if (pq.empty()) {
                cout << "0\n";
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
    return 0;
}