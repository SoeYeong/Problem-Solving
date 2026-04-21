#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a=2;
    while(a<=n && n!=1){
        if(n%a==0) {
            cout << a << "\n";
            n = n/a;
            a=2;
        }
        else {
            a++;
        }
    }
    
    return 0;
}