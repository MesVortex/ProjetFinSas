#include <stdio.h>
#include <stdlib.h>

int main(){
    int size,p,nbr[100],temp;
    printf("donner la taille du tableau:");
    scanf("%d", &size);
    for(int i=0;i<size;i++){
        printf("commmencer a remplir le tableau (N~%d):",i+1);
        scanf("%d", &nbr[i]);
    }
    printf("vous pouvez ajouter un nbr\n");
    printf("donner ce nbr:");
    scanf("%d", &temp);
    printf("donner sa position:");
    scanf("%d", &p);
    again:
        if((p <= 0) || (p > size + 1)){
            printf("donner une postion entre 1 et %d !!\n position:", size+1);
            scanf("%d", &p);
            goto again;
        }
    for (int i = size; i >= p; i--){
        nbr[i]= nbr[i-1];
    }
    nbr[p-1]=temp;
    printf("voila votre tableau:\n");
    for(int i=0 ;i < size + 1 ; i++){
        printf("%d\n",nbr[i]);
    }
    return 0;
}