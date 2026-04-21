#include <iostream>
using namespace std;

int x, y, w, h;

int minimum(){
    int m = x;
    if(m > y)
        m=y;
    if(m > w-x)
        m=w-x;
    if(m > h-y)
        m=h-y;
    
    return m;
}

int main(){
    cin >> x >> y >> w >> h;
    
    int minn = minimum();
    cout << minn;
    return 0;
}