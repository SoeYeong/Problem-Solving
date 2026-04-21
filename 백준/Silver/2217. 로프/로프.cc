#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans;
vector<int> rope;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		rope.push_back(temp);
	}
	sort(rope.begin(), rope.end());

	for (int i = 0; i < N; i++) {
		ans = max(rope[i] * (N-i), ans);
	}
	cout << ans;
	return 0;
}