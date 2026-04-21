#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, x;
string cmd;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			q.push(x);
		}
		else if (cmd == "size")
			cout << q.size() << "\n";
		else if (cmd == "empty")
			cout << q.empty() << "\n";
		else if (q.empty())
			cout << "-1\n";
		else if (cmd == "pop") {
			cout << q.front() << "\n";
			q.pop();
		}
		else if (cmd == "front")
			cout << q.front() << "\n";
		else if (cmd == "back")
			cout << q.back() << "\n";
	}
	return 0;
}