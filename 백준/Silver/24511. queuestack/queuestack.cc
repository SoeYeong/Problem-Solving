#include <iostream>
#include <deque>
using namespace std;

int n, x, m;
int a[100001];
deque<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		if(!a[i])
			q.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		q.push_front(x);
		cout << q.back() << " ";
		q.pop_back();
	}
}