#include <stdio.h>
#include <stdlib.h>

int main(){
    int size,p,nbr[100];
    printf("donner la taille du tableau:");
    scanf("%d", &size);
    for(int i=0;i<size;i++){
        printf("commmencer a remplir le tableau (N~%d):",i+1);
        scanf("%d", &nbr[i]);
    }
    printf("vous pouvez supprimer un nbr\n");
    printf("donner sa position:");
    scanf("%d", &p);
    again:
        if((p <= 0) || (p > size)){
            printf("donner une postion entre 1 et %d !!\n position:", size+1);
            scanf("%d", &p);
            goto again;
        }
    for (int i = p; i < size; i++){
        nbr[i-1]= nbr[i];
    }
    printf("voila votre tableau:\n");
    for(int i=0 ;i < size - 1 ; i++){
        printf("%d\n",nbr[i]);
    }
    return 0;
}