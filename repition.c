#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,cmpt;
    printf("entrer la taille de votre tableau:");
    scanf("%d",&n);
    int nbr[n],frq[n];
    for (int i = 0; i < n; i++){
        printf("remplir votre tableau (N~%d):",i+1);
        scanf("%d", &nbr[i]);
        frq[i]=-1;
    }
    for (int i = 0; i < n; i++){
        cmpt=1;
        for (int j = i+1; j < n; j++){
            if (nbr[i]==nbr[j]){
                frq[j]=0;
                cmpt++;
            }
        }
        if (frq[i]!=0){
            frq[i]=cmpt;
        }
    }
    for (int i = 0; i < n; i++){
        if (frq[i]!=0){
            printf("l\'element %d a ete repeter %d fois\n", nbr[i],frq[i]);
        }
    }
    return 0;
}