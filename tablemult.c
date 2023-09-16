#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    printf("table de multiplication\n");
    printf("donner un nbr:");
    scanf("%d",&a);
    for (int i = 1; i < 11; i++){
        printf("%d x %d = %d \n", i, a, a*i);
    }
    return 0;
}