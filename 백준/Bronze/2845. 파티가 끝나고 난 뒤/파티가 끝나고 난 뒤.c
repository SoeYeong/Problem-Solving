#include <stdio.h>

int main(){
    int L, P;
    int n1, n2, n3, n4, n5;
    
    scanf("%d %d", &L, &P);
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
    
    printf("%d %d %d %d %d", n1-L*P, n2-L*P, n3-L*P, n4-L*P, n5-L*P);
    
    return 0;
}