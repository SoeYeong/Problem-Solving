#include <iostream>
using namespace std;

string str;
long long ans;
long long color() {
	if(str == "black")
		return 0;
	else if (str == "brown")
		return 1;
	else if (str == "red")
		return 2;
	else if (str == "orange")
		return 3;
	else if (str == "yellow")
		return 4;
	else if (str == "green")
		return 5;
	else if (str == "blue")
		return 6;
	else if (str == "violet")
		return 7;
	else if (str == "grey")
		return 8;
	else if (str == "white")
		return 9;
}
long long color2() {
	if (str == "black")
		return 1;
	else if (str == "brown")
		return 10;
	else if (str == "red")
		return 100;
	else if (str == "orange")
		return 1000;
	else if (str == "yellow")
		return 10000;
	else if (str == "green")
		return 100000;
	else if (str == "blue")
		return 1000000;
	else if (str == "violet")
		return 10000000;
	else if (str == "grey")
		return 100000000;
	else if (str == "white")
		return 1000000000;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	ans += color() * 10;
	cin >> str;
	ans += color();
	cin >> str;
	ans *= color2();
	cout << ans;
}