#include <iostream>
using namespace std;

string board[8];
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> board[i];

	for (int i = 0; i < 8; i++) {
		if (i % 2) // 홀수
		{
			for (int j = 1; j < 8; j += 2) {
				if (board[i][j] == 'F')
					ans++;
			}
		}
		else // 짝수
		{
			for (int j = 0; j < 8; j += 2) {
				if (board[i][j] == 'F')
					ans++;
			}
		}
	}
	cout << ans;
}