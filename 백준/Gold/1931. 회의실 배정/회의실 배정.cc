#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cnt = 1;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end(), compare);

	int time = v[0].second;
	for (int i = 1; i < N; i++) {
		if (time <= v[i].first) {
			cnt++;
			time = v[i].second;
		}
	}
	cout << cnt;
	return 0;
}