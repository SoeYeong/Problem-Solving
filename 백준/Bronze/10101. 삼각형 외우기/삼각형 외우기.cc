#include <iostream>
#include <string>
using namespace std;

int a, b, c;
string result="";

int main(){
    cin >> a >> b >> c;

    if(a+b+c != 180){
        result = "Error";
    }
    else{
        if(a==b && b==c)
            result = "Equilateral";
        else if(a==b || b==c || a==c)
            result = "Isosceles";
        else
            result = "Scalene";
    }
    
    cout << result;
    return 0;
}