#include <stdio.h>

int main(){
    int t, i, sum;
    sum=0;
    
    for(i=0; i<4; i++){
        scanf("%d", &t);
        sum+=t;
    }
    
    printf("%d\n%d\n", sum/60, sum%60);
    
    return 0;
}