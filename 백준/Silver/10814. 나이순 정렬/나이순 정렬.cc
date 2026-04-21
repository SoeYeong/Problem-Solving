#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person {
	int age = 0, idx = 0;
	string name = "";
};
bool cmp(person& a, person& b) {
	if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return a.idx < b.idx;
	}
}

int n;
person _person[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> _person[i].age >> _person[i].name;
		_person[i].idx = i;
	}
	sort(_person, _person + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << _person[i].age << " " << _person[i].name << "\n";
	}
	return 0;
}