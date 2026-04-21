#include <iostream>
#include <stack>
using namespace std;

int k, n, sum;
stack<int> s;
int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n)
			s.push(n);
		else
			s.pop();
	}

	while (s.size()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}