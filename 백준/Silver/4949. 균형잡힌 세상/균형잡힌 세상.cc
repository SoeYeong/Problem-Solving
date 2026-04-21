#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int main() {
	while (1) {
		getline(cin, str);
		if (str == ".")
			break;

		stack<char> s;
		for (int i = 0; i < str.length() - 1; i++) {
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else s.push(str[i]);
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else s.push(str[i]);
			}
		}

		if (s.empty()) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}