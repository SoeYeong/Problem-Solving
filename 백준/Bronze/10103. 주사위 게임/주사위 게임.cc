#include <iostream>
using namespace std;

int N;
int score[2] = { 100, 100 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) score[1] -= a;
		else if (a < b) score[0] -= b;
	}
	
	cout << score[0] << "\n" << score[1];
	return 0;
}