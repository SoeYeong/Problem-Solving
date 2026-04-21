#include <iostream>
using namespace std;

int N, M;
long long arr[10001];
int cnt;
int low = 1, high = 1;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	while (high <= N) {
		if (arr[high] - arr[low - 1] > M) {
			low++;
		}
		else if (arr[high] - arr[low - 1] < M) {
			high++;
		}
		else {
			cnt++;
			high++;
		}
	}

	cout << cnt;
	return 0;
}