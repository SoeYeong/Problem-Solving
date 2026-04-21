#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> budget;
int answer;
void binary_search() {
	int low = 0;
	int high = budget[N - 1];

	while (low <= high) {
		int sum = 0;
		int mid = (low + high) / 2;

		for (int i = 0; i < N; i++) {
			sum += min(budget[i], mid);
		}

		if (sum > M) {
			high = mid - 1;
		}
		else {
			answer = mid;
			low = mid + 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		budget.push_back(temp);
	}
	cin >> M;

	sort(budget.begin(), budget.end());
	binary_search();
	cout << answer;
	return 0;
}