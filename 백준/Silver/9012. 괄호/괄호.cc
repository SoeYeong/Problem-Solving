#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string ps;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ps;

		stack<char> s;
		for (int j = 0; j < ps.length(); j++) {
			if (s.size() && ps[j] == ')' && s.top() == '(')
				s.pop();
			else 
				s.push(ps[j]);
		}

		if (s.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}