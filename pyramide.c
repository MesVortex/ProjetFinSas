#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    printf("donner le nbr de ligne:");
    scanf("%d", &a);
    for ( int i = 0; i < a+2; i+=2){
        for (int j = 0; j < i; j++){
            printf("*");
        }
        printf("*\n");
    }
    
    return 0;
}
