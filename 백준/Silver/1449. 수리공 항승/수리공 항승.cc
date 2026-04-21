#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int> hole;
int cnt = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		hole.push_back(n);
	}
	sort(hole.begin(), hole.end());

	int pivot = hole[0];
	for (int i = 1; i < N; i++) {
		if (hole[i] < pivot + L)
			continue;
		cnt++;
		pivot = hole[i];
	}

	cout << cnt;
	return 0;
}