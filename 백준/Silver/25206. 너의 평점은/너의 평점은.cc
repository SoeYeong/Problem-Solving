#include <iostream>
using namespace std;

string subject, grade;
double num, num_sum, sum;

double grade_return(string grade) {
	if (grade == "A+") return 4.5;
	else if (grade == "A0") return 4.0;
	else if (grade == "B+") return 3.5;
	else if (grade == "B0") return 3.0;
	else if (grade == "C+") return 2.5;
	else if (grade == "C0") return 2.0;
	else if (grade == "D+") return 1.5;
	else if (grade == "D0") return 1.0;
	else return 0;
}
int main() {
	for (int i = 0; i < 20; i++) {
		cin >> subject >> num >> grade;
		if (grade == "P")
			continue;
		num_sum += num;
		sum += num * grade_return(grade);
	}
	cout << sum / num_sum;
	return 0;
}