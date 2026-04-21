#include <iostream>
#include <cstring>
using namespace std;

int t, r;
char str[50];
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf("%d %s", &r, &str);
		for (int j = 0; j < strlen(str); j++) {
			for (int k = 0; k < r; k++)
				cout << str[j];
		}
		cout << "\n";
	}
	return 0;
}