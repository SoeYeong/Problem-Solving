#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

float n, score;
float sum, avg;
vector<float> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> score;
		v.push_back(score);
	}
	sort(v.begin(), v.end());

	int num = round(n * 0.15);
	for (int i = num; i < n - num; i++)
		sum += v[i];

	avg = sum / (n - 2 * num);
	int ans = round(avg);
	cout << ans;
	return 0;
}