#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];
int main() {
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);

	if (arr[2] < arr[0] + arr[1])
		cout << arr[0] + arr[1] + arr[2];
	else
		cout << (arr[0] + arr[1]) * 2 - 1;

	return 0;
}