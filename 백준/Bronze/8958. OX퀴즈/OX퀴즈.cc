#include <iostream>
#include <string>
using namespace std;

int n, score, sum;
string str;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') {
				score++;
				sum += score;
			}
			else
				score = 0;
		}
		cout << sum << "\n";
		sum = 0;
		score = 0;
	}
	return 0;
}