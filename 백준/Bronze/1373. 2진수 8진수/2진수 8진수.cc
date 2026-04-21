#include <iostream>
#include <string>
using namespace std;

string binary;
int num;
int main() {
	cin >> binary;
	while (binary.length() % 3) {
		binary = '0' + binary;
	}
	for (int i = 0; i < binary.length(); i += 3) {
		num = (binary[i] - '0') * 4 + (binary[i + 1] - '0') * 2 + (binary[i + 2] - '0');
		cout << num;
	}

	return 0;
}