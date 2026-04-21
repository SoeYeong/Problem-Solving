#include <iostream>
using namespace std;

int h1, m1, s1, h2, m2, s2;
int h, m, s;
int main() {
	for (int i = 0; i < 3; i++) {
		m = 0; 
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		h = h2 - h1;
		
		s = s2 - s1;
		if (s < 0) {
			s += 60;
			m--;
		}

		m += m2 - m1;
		if (m < 0) {
			m += 60;
			h--;
		}
		cout << h << " " << m << " " << s << "\n";
	}
	
	return 0;
}