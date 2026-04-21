#include <iostream>
#include <deque>
using namespace std;

int n;
int arr[1001];
deque<int> dq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	while (1) {
		int temp = dq.front();
		cout << temp << " ";
		dq.pop_front();
		if (dq.empty())
			break;

		if (arr[temp] > 0) {
			while (--arr[temp]) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (arr[temp]++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}