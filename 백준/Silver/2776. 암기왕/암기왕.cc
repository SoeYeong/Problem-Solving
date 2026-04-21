#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
vector<int> note1;
vector<int> note2;
void binary_search(int n) {
	int low = 0;
	int high = note1.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (n == note1[mid]) {
			cout << "1\n";
			return;
		}
		else if (n < note1[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << "0\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int n;
		for (int j = 0; j < N; j++) {
			cin >> n;
			note1.push_back(n);
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> n;
			note2.push_back(n);
		}

		note1.erase(unique(note1.begin(), note1.end()), note1.end());
		sort(note1.begin(), note1.end());
		for (int j = 0; j < M; j++) {
			binary_search(note2[j]);
		}

		note1.clear();
		note2.clear();
	}
	return 0;
}