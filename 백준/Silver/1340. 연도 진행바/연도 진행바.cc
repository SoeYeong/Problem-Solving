#include <iostream>
using namespace std;

string month, comma, timee;
int day, year, hour, minute;
double sum, ans;

int month2day() {
	int ret = 0;
	if (month == "January")
		return 0;
	else if (month == "February")
		return 31;
	else if (year % 400 == 0)
		ret++;
	else if (year % 4 == 0 && year % 100)
		ret++;

	if (month == "March")
		return ret + 59;
	else if (month == "April")
		return ret + 90;
	else if (month == "May")
		return ret + 120;
	else if (month == "June")
		return ret + 151;
	else if (month == "July")
		return ret + 181;
	else if (month == "August")
		return ret + 212;
	else if (month == "September")
		return ret + 243;
	else if (month == "October")
		return ret + 273;
	else if (month == "November")
		return ret + 304;
	else if (month == "December")
		return ret + 334;
}
double all() {
	if (year % 400 == 0)
		return 366 * 24 * 60;
	else if (year % 4 == 0 && year % 100)
		return 366 * 24 * 60;
	else
		return 365 * 24 * 60;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> month >> day >> comma;
	cin >> year >> timee;
	hour = 10 * (timee[0] - '0') + timee[1] - '0';
	minute = 10 * (timee[3] - '0') + timee[4] - '0';

	sum += month2day() * 24 * 60;
	sum += (day - 1) * 24 * 60;
	sum += hour * 60;
	sum += minute;

	ans = sum / all() * 100;
	cout << fixed;
	cout.precision(10);
	cout << ans;
}