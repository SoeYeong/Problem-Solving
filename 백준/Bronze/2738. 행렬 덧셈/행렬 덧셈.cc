#include <iostream>
using namespace std;

int N, M;
int arr1[100][100];
int arr2[100][100];
int ans[100][100];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans[i][j] = arr1[i][j] + arr2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}