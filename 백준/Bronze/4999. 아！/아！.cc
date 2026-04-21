#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    
    if(b.length() <= a.length())
        cout << "go";
    else
        cout << "no";
    return 0;
}