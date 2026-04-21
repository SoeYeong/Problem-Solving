#include <iostream>
using namespace std;

int N, M, B;
int map[501][501];
int min_t = 0x7fffffff;
int max_h;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int h = 0; h <= 256; h++) {
		int build = 0;
		int remove = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int diff = map[i][j] - h;
				if (diff > 0) remove += diff;
				else build -= diff;
			}
		}
		if (remove + B >= build) {
			int time = remove * 2 + build;
			if (min_t >= time) {
				min_t = time;
				max_h = h;
			}
		}
	}

	cout << min_t << " " << max_h;
}