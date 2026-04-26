#include <iostream>
using namespace std;

int C, N;
float score[1001];
double average, ratio;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;

        average = 0;
        ratio = 0;
        for (int j = 0; j < N; j++) {
            cin >> score[j];
            average += score[j];
        }

        average = average / N;
        for (int j = 0; j < N; j++) {
            if (score[j] > average) {
                ratio++;
            }
        }
        ratio = ratio / N * 100;
        cout << fixed;
        cout.precision(3);
        cout << ratio << "%\n";
    }
    return 0;
}