#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
unordered_map <string, int> m;
bool cmp(pair<string, int> &a, pair<string, int> &b) {
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
			return a.first < b.first;
		return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	string word;
	for (int i = 0; i < N; i++) {
		cin >> word;
		if (word.length() >= M)
			m[word]++;
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}
}