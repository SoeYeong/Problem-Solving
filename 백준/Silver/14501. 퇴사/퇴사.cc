#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 17
int N;
int Ti[MAX];
int Pi[MAX];
int sum[MAX];

void Dp() {
    int deadline;
    for (int i = N; i > 0; i--) {
        deadline = i + Ti[i];
        if (deadline > N + 1) {
            // 상담 불가
            sum[i] = sum[i + 1];
        }
        else {
            // 상담 가능
            sum[i] = max(sum[i + 1], sum[deadline] + Pi[i]);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> Ti[i] >> Pi[i];
    }
    Dp();
    cout << sum[1];
    return 0;
}