#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		getline(cin, str);
		if (str == "END") break;
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}
}