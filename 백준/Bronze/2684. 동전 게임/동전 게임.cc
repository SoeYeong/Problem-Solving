#include <iostream>
#include <string>
using namespace std;

int p;
int arr[8];
string str[1000];
string coin[8] = { "TTT", "TTH", "THT", "THH", "HTT","HTH","HHT","HHH" };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < p; i++) {
		for (int j = 0; j <= 38; j++) {
			string temp = str[i].substr(j, 3);
			for (int k = 0; k < 8; k++) {
				if (temp == coin[k]) arr[k]++;
			}
		}

		for (int k = 0; k < 8; k++) {
			cout << arr[k] << " ";
		}
		cout << "\n";

		for (int k = 0; k < 8; k++) {
			arr[k] = 0;
		}
	}
}