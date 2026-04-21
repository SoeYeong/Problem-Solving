#include <stdio.h>

int main(){
    int score, i;
    int sum=0;
    
    for(i=0;i<5;i++){
        scanf("%d", &score);
        if(score<40)
            sum+=40;
        else
            sum+=score;
    }
    
    printf("%d", sum/5);
    
    return 0;
}