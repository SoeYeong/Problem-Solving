#include <iostream>
using namespace std;

int n, call;
int y_sum, m_sum;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> call;
		y_sum += (call / 30 + 1) * 10;
		m_sum += (call / 60 + 1) * 15;
	}
	if (y_sum > m_sum) cout << "M " << m_sum;
	else if (y_sum < m_sum) cout << "Y " << y_sum;
	else cout << "Y M " << m_sum;
	return 0;
}