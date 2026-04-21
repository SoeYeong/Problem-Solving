#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX 100001
using namespace std;

int T, N;
struct info {
    int resume, interview;
};
info applicant[MAX];

bool cmp(info a, info b) {
    if (a.resume != b.resume) {
        return a.resume < b.resume;
    }
    return a.interview < b.interview;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> applicant[i].resume >> applicant[i].interview;
        }
        sort(applicant, applicant + N, cmp);

        int cnt = 0;
        int maxx = applicant[0].interview;
        for (int i = 0; i < N; i++) {
            if (applicant[i].interview <= maxx) {
                cnt++;
                maxx = applicant[i].interview;
            }
        }

        cout << cnt << "\n";
        memset(applicant, 0, sizeof(applicant));
    }

    return 0;
}