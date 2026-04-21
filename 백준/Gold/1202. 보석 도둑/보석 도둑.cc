#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
long long result;
struct jewel {
    int m, v;
};
vector<jewel> j;
vector<int> bag;

struct compare {
    bool operator()(jewel &a, jewel &b) {
        if (a.v != b.v) return a.v < b.v;
        return a.m < b.m;
    }
};
priority_queue<jewel, vector<jewel>, compare> pq;

bool comp(jewel &a, jewel &b) {
    if (a.m != b.m) return a.m < b.m;
    return a.v < b.v;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        j.push_back({ m, v });
    }
    for (int i = 0; i < K; i++) {
        int b;
        cin >> b;
        bag.push_back(b);
    }

    // 가방 오름차순 정렬
    sort(bag.begin(), bag.end());

    // 보석 무게 기준 오름차순 정렬
    sort(j.begin(), j.end(), comp);

    // 가방 작은 것부터 선택
    int n = 0;
    for (int i = 0; i < K; i++) {
        // 가방에 넣을 수 있는 보석을 최대 힙(우선순위 큐)에 push
        while (n < N && j[n].m <= bag[i]) {
            pq.push(j[n]);
            n++;
        }

        // 최대 가격 보석 선택
        if (pq.empty()) {
            continue;
        }
        result += pq.top().v;
        pq.pop();
    }

    cout << result;
    return 0;
}