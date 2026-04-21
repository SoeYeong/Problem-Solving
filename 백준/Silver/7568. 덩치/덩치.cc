#include <iostream>
using namespace std;

struct body {
	int w, h;
};

int n;
body b[51];
int r[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i].w >> b[i].h;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i].w < b[j].w && b[i].h < b[j].h)
				r[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << r[i] + 1 << " ";
	}
}