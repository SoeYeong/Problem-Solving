#include <iostream>
#include <string>

using namespace std;

string input;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;

    bool flag = false, possible = true;;
    int i = 0;
    while (i < input.size()) {
        if (flag) {
            i++;
            while (i < input.size()) {
                if (input[i] == '1') {
                    if (i < input.size() - 2 && input[i + 1] == '0' && input[i + 2] == '0') {
                        break;
                    }
                    else {
                        i++;
                    }
                }
                else {
                    break;
                }
            }
            flag = false;
        }
        else if (input.substr(i, 2) == "01") {
            i += 2;
        }
        else if (input.substr(i, 3) == "100") {
            flag = true;
            i += 3;
            while (i <= input.size()) {
                if (i == input.size()) {
                    possible = false;
                    break;
                }
                if (input[i] == '0') {
                    i++;
                }
                else {
                    break;
                }
            }
        }
        else {
            possible = false;
            break;
        }
    }

    if (possible)
        cout << "SUBMARINE";
    else
        cout << "NOISE";
    return 0;
}