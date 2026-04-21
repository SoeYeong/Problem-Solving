#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (1) {
		cout << q.front() << " ";
		q.pop();
		if (q.empty()) break;
		q.push(q.front());
		q.pop();
	}
}