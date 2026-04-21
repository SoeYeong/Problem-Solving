#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
stack <pair<int, int>> s;
vector <int> v;
int main() {
	cin >> N;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		while (!s.empty() && s.top().first <= num) {
			s.pop();
		}
		if (s.empty()) {
			v.push_back(0);
		}
		else {
			v.push_back(s.top().second);
		}
		s.push({ num, i });
	}

	for (int i = 0; i < N; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}