#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,temp;
    printf("entrer la taille de votre tableau:");
    scanf("%d",&n);
    int nbr[n];
    for (int i = 0; i < n; i++){
        printf("remplir votre tableau (N~%d):",i+1);
        scanf("%d", &nbr[i]);
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (nbr[i] < nbr[j] ){
                temp = nbr[i];
                nbr[i] = nbr[j];
                nbr[j] = temp;
            }
        }
    }
    printf("voila votre tableau trier!!\n");
    for (int i = 0; i < n; i++){
        printf("%d\t",nbr[i]);
    }
    printf("\n");
    return 0;
}