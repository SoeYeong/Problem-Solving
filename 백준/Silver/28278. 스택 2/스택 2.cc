#include <iostream>
#include <stack>
using namespace std;

int n, cmd, x;
stack<int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> x;
			s.push(x);
		}
		else if (cmd == 3) {
			cout << s.size() << "\n";
		}
		else if (cmd == 4) {
			cout << s.empty() << "\n";
		}
		else if (s.empty())
			cout << "-1\n";
		else if (cmd == 2) {
			cout << s.top() << "\n";
			s.pop();
		}
		else
			cout << s.top() << "\n";
	}
	return 0;
}