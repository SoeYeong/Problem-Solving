#include <iostream>
using namespace std;

int N, K;
int line[10000];
long long ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long left = 1, right = 0;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		right = line[i] > right ? line[i] : right;
	}

	while (left <= right) {
		long long mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 0; i < K; i++) {
			cnt += (line[i] / mid);
		}
		if (cnt >= N) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
}