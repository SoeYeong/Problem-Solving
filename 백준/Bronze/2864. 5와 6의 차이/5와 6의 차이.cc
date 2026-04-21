#include <iostream>
#include <string>
using namespace std;

string a, b;
string minA, maxA, minB, maxB;
int minn, maxx;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '5') {
			maxA += '6';
			minA += a[i];
		}
		else if (a[i] == '6') {
			minA += '5';
			maxA += a[i];
		}
		else {
			minA += a[i];
			maxA += a[i];
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == '5') {
			maxB += '6';
			minB += b[i];
		}
		else if (b[i] == '6') {
			minB += '5';
			maxB += b[i];
		}
		else {
			minB += b[i];
			maxB += b[i];
		}
	}
	minn = stoi(minA) + stoi(minB);
	maxx = stoi(maxA) + stoi(maxB);
	cout << minn << " " << maxx;
	return 0;
}