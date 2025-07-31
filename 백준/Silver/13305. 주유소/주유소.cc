#include <iostream>
using namespace std;

int N, minCity;
long long roadSum;
long long city[100001], road[100001];
long long cost[100001];
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

    cost[0] = city[0] * road[0];
    minCity = city[0];
    for (int i = 1; i < N; i++) {
        if (city[i] <= minCity) {
            cost[i] = minCity * roadSum;
            minCity = city[i];
            roadSum = road[i];
        }
        else {
            roadSum += road[i];
        }
        cost[i] += cost[i - 1];
    }

    cout << cost[N - 1];

    return 0;
}