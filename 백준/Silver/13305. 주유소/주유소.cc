#include <iostream>
#include <algorithm>
using namespace std;

int N, minCity;
long long roadSum;
long long city[100001], road[100001];
long long cost;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> city[i];
    }

    minCity = 1000000001;
    for (int i = 0; i < N; i++) {
        if (city[i] < minCity) {
            minCity = city[i];
        }
        cost += (long long)minCity * road[i];
    }

    cout << cost;

    return 0;
}