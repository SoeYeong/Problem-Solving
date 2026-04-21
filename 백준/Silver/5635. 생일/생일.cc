#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct student {
	string name="";
	int dd=0;
	int mm=0;
	int yyyy=0;
};
student students[101];
bool cmp(student &a, student &b) {
	if (a.yyyy == b.yyyy) {
		if (a.mm == b.mm)
			return a.dd < b.dd;
		else
			return a.mm < b.mm;
	}
	else
		return a.yyyy < b.yyyy;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> students[i].name >> students[i].dd >> students[i].mm >> students[i].yyyy;
	}

	sort(students, students + n, cmp);
	cout << students[n - 1].name << "\n";
	cout << students[0].name;
	return 0;
}