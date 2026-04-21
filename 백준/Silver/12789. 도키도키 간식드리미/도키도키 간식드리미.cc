#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, x, now = 1;
queue<int> q;
stack<int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}

	while (!q.empty()) {
		if (q.front() == now) {
			q.pop();
			now++;
		}
		else if (!s.empty() && s.top() == now) {
			s.pop();
			now++;
		}
		else {
			s.push(q.front());
			q.pop();
		}
	}

	while (!s.empty()) {
		int temp = s.top();
		if (temp == now) {
			s.pop();
			now++;
		}
		else
			break;
	}

	if (s.empty()) cout << "Nice";
	else cout << "Sad";
	return 0;
}