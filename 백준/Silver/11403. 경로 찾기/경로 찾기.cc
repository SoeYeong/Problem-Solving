#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> graph[101];
int visit[101];
void dfs(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		if (visit[graph[x][i]]) continue;
		visit[graph[x][i]] = 1;
		dfs(graph[x][i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if(temp)
				graph[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
		for (int j = 0; j < N; j++) {
			cout << visit[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}