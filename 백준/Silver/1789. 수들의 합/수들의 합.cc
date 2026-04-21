#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long S;
	long long N = 0;
	long long i = 1;
	long long sum = 0;

	cin >> S;
	while (1) {
		sum += i;
		N++;
		if (sum > S) {
			N--;
			break;
		}
		i++;
	}
	cout << N;
	return 0;
}