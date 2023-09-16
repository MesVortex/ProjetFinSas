#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=0,max,sum,a[200];
    printf("\t serie d\'entier \n\n\n");
    do{
        printf("donner le nbr N°%d :",i+1);
        scanf("%d", &a[i]);
        if ((a[i] < 0) || (a[i] > 100)){
            printf("les nbr negatives et les nbr superieurs a 100 sont interdit!!\n");
            i--;
        }
        if (a[i] > a[i-1])
            max = a[i];
        sum = sum + a[i];
        i++;
        if (i >= 200){
            printf("vous avez atteint la limite des nbrs!\n");
            break;
        }
    } while (a[i-1] != 0);
    printf("la somme est : %d\n",sum);
    printf("le maximum est : %d\n",max);
    return 0;
}