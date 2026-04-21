#include <stdio.h>

int main(){
    
    int i, Ai, sum;
    sum = 0;
    
    for (i=0; i<5; i++){
        scanf("%d", &Ai);
        sum += Ai;
    }
    printf("%d", sum);
    
    return 0;
}