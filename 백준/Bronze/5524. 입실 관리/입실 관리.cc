#include <iostream>
#include <string>
using namespace std;

int n;
string name;
int main() {
	cin >> n;
	while (n--) {
		cin >> name;
		for (int i = 0; i < name.length(); i++) {
			if (name[i] >= 'A' && name[i] <= 'Z')
				name[i] += 'a' - 'A';
		}
		cout << name << "\n";
	}
	return 0;
}