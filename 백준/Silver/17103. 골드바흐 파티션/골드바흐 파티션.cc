#include <iostream>
using namespace std;

int T, N;
int arr[1000001];
void prime() {
	for (int i = 2; i < 1000001; i++) {
		arr[i] = i;
	}
	for (int i = 2; i*i < 1000001; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j < 1000001; j += i) {
			arr[j] = 0;
		}
	}
}
int solve(int n) {
	int cnt = 0;
	for (int i = 2; i < n; i++) {
		if (arr[n - i] + arr[i] == n) {
			cnt++;
			if (n - i == i) {
				cnt++;
			}
		}
	}
	return cnt / 2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	prime();
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int answer = solve(N);
		cout << answer << '\n';
	}

	return 0;
}