#include <iostream>
#include <string>
using namespace std;

string str;
int cnt, sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	while (str.length() > 1) {
		sum = 0;
		for (int i = 0; i < str.length(); i++) {
			sum += str[i] - '0';
		}
		str = to_string(sum);
		cnt++;
	}
	cout << cnt << "\n";
	if (str == "3" || str == "6" || str == "9") cout << "YES";
	else cout << "NO";
}