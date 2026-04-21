#include <iostream>
#include <algorithm>
using namespace std;

string num1, num2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	if (num1 > num2) cout << num1;
	else cout << num2;
}