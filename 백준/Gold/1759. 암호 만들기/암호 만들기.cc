#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char input[16];
char output[16];
bool check() {
	int aeiou = 0;
	for (int i = 0; i < L; i++) {
		if (output[i] == 'a' || output[i] == 'e' || output[i] == 'i' || 
			output[i] == 'o' || output[i] == 'u') {
			aeiou++;
		}
	}
	if (aeiou >= 1 && (L-aeiou) >= 2) {
		return true;
	}
	return false;
}
void dfs(int cnt, int idx) {
	if (cnt == L) {
		if (check()) {
			for (int i = 0; i < L; i++) {
				cout << output[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int j = idx; j < C; j++) {
		output[cnt] = input[j];
		dfs(cnt + 1, j + 1);
	}
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> input[i];
	}
	sort(input, input + C);

	dfs(0, 0);
	return 0;
}
