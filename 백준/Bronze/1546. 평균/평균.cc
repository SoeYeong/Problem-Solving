#include <iostream>
#include <algorithm>
using namespace std;

int n;
double maxx, sum, avg;
double score[1000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		maxx = max(score[i], maxx);
		sum += score[i];
	}
	sum = sum / maxx * 100;
	avg = sum / n;
	cout << avg;
	return 0;
}