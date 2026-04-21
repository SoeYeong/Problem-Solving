#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
int cmd, r, c, v;
vector<int> row;
vector<int> col;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		row.push_back(0);
	for (int i = 0; i < m; i++)
		col.push_back(0);

	for (int i = 0; i < q; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> r >> v;
			row[r - 1] += v;
		}
		else {
			cin >> c >> v;
			col[c - 1] += v;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << row[i] + col[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}