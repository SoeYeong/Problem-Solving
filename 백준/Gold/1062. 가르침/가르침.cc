#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int maxx = 0;
string words[51];
bool visit[26];
void word_check() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool check = true;
		for (int j = 4; j < words[i].length() - 4; j++) {
			if (!visit[words[i][j] - 'a']) {
				check = false;
				break;
			}
		}
		if (check) {
			cnt++;
		}
	}
	maxx = max(maxx, cnt);
}
void dfs(int cnt, int idx) {
	if (cnt == K - 5) {
		word_check();
		return;
	}
	for (int c = idx; c < 26; c++) {
		if (visit[c]) continue;
		visit[c] = true;
		dfs(cnt + 1, c + 1);
		visit[c] = false;
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}
	visit[0] = true;
	visit['c' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	
	if (K < 5) {
		cout << 0;
		return 0;
	}
	dfs(0, 1);
	cout << maxx;
	return 0;
}
