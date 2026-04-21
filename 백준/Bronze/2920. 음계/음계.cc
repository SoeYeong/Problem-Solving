#include <iostream>
using namespace std;

int note[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
int arr[8];
int flag1, flag2;
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 8; i++) {
		if (arr[i] != note[i]) {
			flag1 = 1;
			break;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (arr[i] != note[7 - i]) {
			flag2 = 1;
			break;
		}
	}

	if (flag1 && flag2) cout << "mixed";
	else if (flag1) cout << "descending";
	else cout << "ascending";
	return 0;
}