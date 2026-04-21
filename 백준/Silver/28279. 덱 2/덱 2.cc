#include <iostream>
#include <deque>
using namespace std;

int n, cmd, x;
deque<int> dq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> x;
			dq.push_front(x);
		}
		else if (cmd == 2) {
			cin >> x;
			dq.push_back(x);
		}
		else if (cmd == 5)
			cout << dq.size() << "\n";
		else if (cmd == 6)
			cout << dq.empty() << "\n";
		else if (dq.empty())
			cout << "-1\n";
		else if (cmd == 3) {
			cout << dq.front() << "\n";
			dq.pop_front();
		}
		else if (cmd == 4) {
			cout << dq.back() << "\n";
			dq.pop_back();
		}
		else if (cmd == 7)
			cout << dq.front() << "\n";
		else
			cout << dq.back() << "\n";
	}
	return 0;
}