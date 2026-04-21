#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];
int main() {
	while (1) {
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
		sort(arr, arr + 3);

		if (arr[2] >= arr[0] + arr[1])
			cout << "Invalid\n";
		else if (arr[0] != arr[1] && arr[1] != arr[2] && arr[2] != arr[0])
			cout << "Scalene\n";
		else if (arr[0] == arr[1] && arr[1] == arr[2])
			cout << "Equilateral\n";
		else
			cout << "Isosceles\n";
	}
	return 0;
}