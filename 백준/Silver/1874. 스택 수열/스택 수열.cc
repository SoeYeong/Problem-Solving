#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, cnt;
int arr[100001];
string ans;
stack<int> s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		s.push(i);
		ans += '+';

		while (!s.empty() && s.top() == arr[cnt]) {
			s.pop();
			ans += '-';
			cnt++;
		}
	}

	if (s.empty()) {
		for (int i = 0; i < ans.length(); i++) {
			cout << ans[i] << "\n";
		}
	}
	else cout << "NO";

	return 0;
}