#include <iostream>
#include <string>
using namespace std;

int n, m, cnt;
string str;
char c[200][20];
int main() {
	cin >> n >> str;
	m = str.length() / n;
	
	for (int i = 0; i < m; i++) {
		if (i % 2) {
			for (int j = n - 1; j >= 0; j--)
			{
				c[i][j] = str[cnt];
				cnt++;
			}
		}
		else {
			for (int j = 0; j < n; j++)
			{
				c[i][j] = str[cnt];
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c[j][i];
		}
	}
	return 0;
}