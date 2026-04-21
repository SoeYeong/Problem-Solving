#include <iostream>
#include <string>
using namespace std;

string str;
int cnt, idx;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	while (idx < str.length()) {
		if (str.substr(idx, 2) == "c=") {
			idx++;
		}
		else if (str.substr(idx, 2) == "c-") {
			idx++;
		}
		else if (str.substr(idx, 3) == "dz=") {
			idx += 2;
		}
		else if (str.substr(idx, 2) == "d-") {
			idx++;
		}
		else if (str.substr(idx, 2) == "lj") {
			idx++;
		}
		else if (str.substr(idx, 2) == "nj") {
			idx++;
		}
		else if (str.substr(idx, 2) == "s=") {
			idx++;
		}
		else if (str.substr(idx, 2) == "z=") {
			idx++;
		}
		cnt++;
		idx++;
	}
	cout << cnt;
	return 0;
}