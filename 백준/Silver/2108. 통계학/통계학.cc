#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int arr[500001];
int cnt[8001];
double sum, avg;
int mid, mode, range;

int get_mode() {
	int max = 0;
	int idx = -1;

	for (int i = 0; i < 8002; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			idx = i;
		}
	}
	for (int i = idx + 1; i < 8002; i++) {
		if (max == cnt[i]) {
			idx = i;
			break;
		}
	}
	return idx;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}
	sort(arr, arr + N);

	avg = round(sum / N);
	mid = arr[(N - 1) / 2];
	mode = get_mode() - 4000;
	range = arr[N - 1] - arr[0];

	cout << (int)avg << "\n";
	cout << mid << "\n";
	cout << mode << "\n";
	cout << range;
}